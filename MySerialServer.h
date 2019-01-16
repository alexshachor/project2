//
// Created by alexander on 1/10/19.
//

#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include "Server.h"
#include <pthread.h>
#include <atomic>
#include <mutex>

#define MAX_LISTEN 5
#define TIMEOUT_SEC 1

class MySerialServer : public server_side::Server {
private:
    std::atomic<bool> runServer;
    mutable std::mutex mut;
public:
    MySerialServer();

    void runServerThread(int port, ClientHandler *clientHandler);

    void open(int port, ClientHandler *clientHandler);

    void stop();

    ~MySerialServer();
};


#endif //PROJECT2_MYSERIALSERVER_H
