//
// Created by alexander on 1/10/19.
//

#ifndef PROJECT2_MYCLIENTHANDLER_H
#define PROJECT2_MYCLIENTHANDLER_H

#include "ClientHandler.h"

class MyClientHandler : public ClientHandler {
public:
    void handleClient(int sockfd);
};


#endif //PROJECT2_MYCLIENTHANDLER_H
