#include "socket.h"

sockaddr_in make_ip_address(int port, const std::string& ip_address = std::string()) {
  // Dirección del socket local
  sockaddr_in local_address{};	// Así se inicializa a 0, como se recomienda
  local_address.sin_family = AF_INET;	// Pues el socket es de dominio AF_INET
  if (ip_address == std::string()) {
    local_address.sin_addr.s_addr = htonl(INADDR_ANY);
  } else {
    inet_aton(reinterpret_cast<const char*>(&ip_address), &local_address.sin_addr);
  }
  local_address.sin_port = htons(port);
  return local_address;
}

int main() {
  sockaddr_in local_address = make_ip_address(2000, "");
  sockaddr_in remote_address = make_ip_address(3000, "");
  Socket socket(local_address);
  File file;
  Message message;

  file.Read(message);
  if (file.GetResult() < 0) {
    std::cerr << "no se pudo leer el archivo: " <<	std::strerror(errno) << '\n';
    return 5;
  }

  do {
    socket.Send_to(message, remote_address);
    file.Read(message);
    std::cout << "sent";
  } while(file.GetResult() > 0);
  return 0;
}