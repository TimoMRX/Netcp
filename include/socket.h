#pragma once
#include <iostream>
#include <cstring>
#include <array>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "message.h"
#include "file.h"

class Socket {
public:
  Socket(const sockaddr_in& address);
  ~Socket();
  void Send_to(const Message& message, const sockaddr_in& address);
  void Receive_from(Message& message, sockaddr_in& address);

private:
  int fd_;
};