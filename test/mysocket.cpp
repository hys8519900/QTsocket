#include "mysocket.h"

MyClientSocket::MyClientSocket(const std::string& host, int port):
    SocketClient(host,port)
{
}

std::string MyClientSocket::ReceiveAll()
{
    std::string ret;
    while(1)
    {
        char r;
        switch(recv(s_,&r,1,0))
        {
        case 0:
            return ret;
        case -1:
            return "";
        }

        ret += r;
    }
}
