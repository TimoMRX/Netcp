#include "socket.h"

Socket::Socket(const sockaddr_in& address) {
  fd_ = socket(AF_INET, SOCK_DGRAM, 0);
  if (fd_ < 0) {
    std::cerr << "no se pudo crear el socket: " <<	std::strerror(errno) << '\n';
  }
  int result = bind(fd_, reinterpret_cast<const sockaddr*>(&address), sizeof(address));
  if (result < 0) {
    std::cerr << "falló bind: " << std::strerror(errno) << '\n';
  }
}

Socket::~Socket() {
  close(fd_);
}

void Socket::Send_to(const Message& message, const sockaddr_in& address) {
  int result = sendto(fd_, &message, sizeof(message), 0, reinterpret_cast<const sockaddr*>(&address), sizeof(address));
  if (result < 0) {
    std::cerr << "falló sendto: " << std::strerror(errno) << '\n';
  }
}

void Socket::Receive_from(Message& message, sockaddr_in& address) {
  socklen_t address_len = sizeof(address);
  int result = recvfrom(fd_, &message, sizeof(message), 0, reinterpret_cast<sockaddr*>(&address), &address_len);
  if (result < 0) {
  std::cerr << "falló recvfrom: " << std::strerror(errno) << '\n';
  }
}