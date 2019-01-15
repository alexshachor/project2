//
// Created by alexander on 1/10/19.
//

#include "MyClientHandler.h"

MyClientHandler::MyClientHandler(Solver<string, string> solver, CacheManager cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

void MyClientHandler::handleClient(int sockfd) {
    posix_sockets::TcpClient client(sockfd);
}