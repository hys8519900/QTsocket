#ifndef MYSOCKET_H
#define MYSOCKET_H

#include "basesocket.h"

class MyClientSocket : public SocketClient
{
public:
    MyClientSocket(const std::string& host, int port);
    std::string ReceiveAll();
};

#endif // MYSOCKET_H
