#include "file.h"

File::File() {
  fd_ = open( "bin/prueba.txt", O_RDONLY);
  if (fd_ < 0) {
    std::cerr << "no se pudo abrir el archivo: " <<	std::strerror(errno) << '\n';
  }
}

File::~File() {
  close(fd_);
}

void File::Read() {

}

void File::Write() {

}
