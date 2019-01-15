//
// Created by alexander on 1/14/19.
//

#ifndef PROJECT2_SOCKETS_H
#define PROJECT2_SOCKETS_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cerrno>
#include "MyExceptions.h"
#include "StringHelper.h"

#define NEW_LINE "\n"
#define BUFFLEN 2046

namespace posix_sockets {
    // struct defining general socket, with general operations (open and close)
    // opening is done in the constructor.
    // the socket is not automatically closed in the destructor so that the object
    // can be passed as a parameter (possibly to another thread)
    struct TcpSocket {
        int sockfd;

        int getSockfd();

        TcpSocket();

        TcpSocket(int openSockfd);

        void close();

        void setTimeout(int sec, int usec = 0);
    };

    class TcpClient {
    private:
        TcpSocket sock;
    public:
        // It makes sense to creates another constructor that
        // will create a client from scratch
        TcpClient(TcpSocket sock);

        int getSockfd();

        void sendMessage(std::string message);

        std::string read(int n);

        std::string readLine();

        std::string readUntil(std::string untilStr);

        void setTimeout(int sec, int usec = 0);

        void close();
    };

    class TcpServer {
    private:
        TcpSocket sock;
    public:
        TcpServer(int port);

        int getSockfd();

        void listen(int maxLis);

        void setTimeout(int sec, int usec = 0);

        TcpClient accept();

        void close();
    };
}


#endif //PROJECT2_SOCKETS_H
