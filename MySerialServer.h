//
// Created by alexander on 1/10/19.
//

#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer : public server_side::Server {
public:
    void open(int port, ClientHandler clientHandler);

    void stop();
};


#endif //PROJECT2_MYSERIALSERVER_H
