//
// Created by alexander on 1/10/19.
//

#include <thread>
#include "MySerialServer.h"


void MySerialServer::runServerThread(int port, ClientHandler clientHandler) {

    posix_sockets::TcpServer tcpServer(port);
    tcpServer.listen(MAX_LISTEN);
    while (runServer) {
        posix_sockets::TcpClient client = tcpServer.accept();
        clientHandler.handleClient(client.getSockfd());
        tcpServer.setTimeout(TIMEOUT_SEC);
    }
    tcpServer.close();
}

MySerialServer::MySerialServer() {
    runServer = false;
}

void MySerialServer::open(int port, ClientHandler clientHandler) {

    runServer = true;
    std::thread serverThread(&MySerialServer::runServerThread, this, port, std::ref(clientHandler));
}

void MySerialServer::stop() {
    std::lock_guard<std::mutex> guard(mut);
    runServer = false;
}