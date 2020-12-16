#include "socket.h"

class File {

public:
  File();
  ~File();
  void Write();
  void Read();
private:
  int fd_;
};