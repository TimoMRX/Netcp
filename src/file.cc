#include "file.h"

File::File() {
  fd_ = open( "bin/prueba.txt", O_RDWR | O_CREAT);
  if (fd_ < 0) {
    std::cerr << "no se pudo abrir el archivo: " <<	std::strerror(errno) << '\n';
  }
}

File::~File() {
  close(fd_);
}

void File::Read(Message& message) {
  result_ = read(fd_, &message, sizeof(message));
}

void File::Write(Message& message) {
  int result;
  do
  {
    result = write(fd_, &message, sizeof(message));
  } while (result > 0);

  if (result < 0) {
    std::cerr << "no se pudo leer el archivo: " <<	std::strerror(errno) << '\n';
  }
}

int File::GetResult() {
  return result_;
}