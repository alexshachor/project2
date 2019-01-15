//
// Created by alexander on 1/14/19.
//

#include "Sockets.h"

using namespace posix_sockets;

int TcpSocket::getSockfd() {
    return this->sockfd;
}

TcpSocket::TcpSocket() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        throw std::system_error(std::error_code(errno, std::generic_category()),
                                "failure on opening socket");
    }
}

TcpSocket::TcpSocket(int openSockfd) {
    this->sockfd = openSockfd;
}

void TcpSocket::close() {
    if (::close(sockfd) < 0) {
        throw std::system_error(std::error_code(errno, std::generic_category()),
                                "failure on closing socket");
    }
}

void TcpSocket::setTimeout(int sec, int usec) {
    timeval timeout;
    timeout.tv_sec = sec;
    timeout.tv_usec = usec;

    // setting socket option for recieve timeout
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,
                   (char *) &timeout, sizeof(timeout)) == -1) {
        throw std::system_error(std::error_code(errno, std::generic_category()), "failure on setsockopt");
    }
}

int TcpClient::getSockfd() {
    return this->sock.getSockfd();
}

TcpClient::TcpClient(TcpSocket sock) : sock(sock) {}

// you should definitely use your own logic here
// suggestions are - read_until (char), read_min(int)
// read_line, etc.
// you can obviously define a write (or send) method
std::string TcpClient::read(int n) {
    char *buffer = new char[n + 1];
    int readLen = ::read(sock.sockfd, buffer, n);
    if (readLen < 0) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            throw timeout_exception("timeout on read");
        }
        throw std::system_error(std::error_code(errno, std::generic_category()), "error on read");
    }

    buffer[readLen] = 0;
    std::string output = std::string(buffer);
    delete[] buffer;
    return output;
}

std::string TcpClient::readLine() {
    return readUntil(NEW_LINE);
}

std::string TcpClient::readUntil(std::string untilStr) {


    size_t buffIndex = 0, untilStrIndex = 0;
    const int numOfBytes = 1;
    char buf[BUFFLEN] = {0};
    std::string output;
    std::string temp;

    while (buffIndex < BUFFLEN) {
        int readLen = ::read(sock.sockfd, &buf[buffIndex], numOfBytes);
        if (readLen < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                throw timeout_exception("timeout on read");
            }
            throw std::system_error(std::error_code(errno, std::generic_category()), "error on read");
        }
        if (buf[buffIndex] == untilStr[untilStrIndex]) {
            temp += buf[buffIndex];
            if (temp == untilStr) {
                break;
            }
            untilStrIndex++;
        } else {
            temp = "";
            untilStrIndex = 0;
        }
        buffIndex++;
    }
    buf[buffIndex + 1] = 0;
    output = std::string(buf);
    return output;
}

void TcpClient::setTimeout(int sec, int usec) {
    sock.setTimeout(sec, usec);
}

void TcpClient::close() {
    sock.close();
}


TcpServer::TcpServer(int port) {
    sockaddr_in addrIn;
    addrIn.sin_family = AF_INET;
    addrIn.sin_port = htons(port);
    addrIn.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock.sockfd, (sockaddr *) &addrIn, sizeof(addrIn)) == -1) {
        throw std::system_error(std::error_code(errno, std::generic_category()), "failure on bind");
    }
}

int TcpServer::getSockfd() {
    return this->sock.getSockfd();
}

void TcpServer::listen(int maxLis) {
    if (::listen(sock.sockfd, maxLis) == -1) {
        throw std::system_error(std::error_code(errno, std::generic_category()), "error on listen");
    }
}

void TcpServer::setTimeout(int sec, int usec) {
    sock.setTimeout(sec, usec);
}

TcpClient TcpServer::accept() {
    sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int clientSockfd = ::accept(sock.sockfd, (sockaddr *) &addr, &len);
    if (clientSockfd < 0) {
        // eagain and ewouldblock are errors normally hapenning on timeouts
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            throw timeout_exception("timeout on accept");
        } else {
            throw std::system_error(std::error_code(errno, std::generic_category()), "error on accept");
        }
    }

    TcpSocket clientSock(clientSockfd);

    // in Unix, client socket have their parents' timeout
    // so we set the timeout to 0 (effectively - infinity)
    // for newly created sockets
    clientSock.setTimeout(0);
    return clientSock;
}

void TcpServer::close() {
    sock.close();
}