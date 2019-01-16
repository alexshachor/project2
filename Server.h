//
// Created by alexander on 1/10/19.
//

#ifndef PROJECT2_SERVER_H
#define PROJECT2_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler *clientHandler) = 0;

        virtual void stop() = 0;
    };
}

#endif //PROJECT2_SERVER_H