#pragma once
#include "socket.h"

class File {

public:
  File();
  ~File();
  void Read(Message& message);
  void Write(Message& message);
  int GetResult();
private:
  int fd_, result_;
};