//
// Created by alexander on 1/9/19.
//

#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(int sockfd) = 0;
};

#endif //PROJECT2_CLIENTHANDLER_H
