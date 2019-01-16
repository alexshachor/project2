//
// Created by alexander on 1/10/19.
//

#ifndef PROJECT2_MYCLIENTHANDLER_H
#define PROJECT2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

#define END_CONVERSATION_WORD "end"
#define VALUES_DELIMETER ","

class MyClientHandler : public ClientHandler {
private:
    Solver<string, vector<vector<string>>> *solver;
    //CacheManager cacheManager;
public:
    MyClientHandler(Solver<string, vector<vector<string>>> *solver, CacheManager *cacheManager);

    void handleClient(int sockfd);

    ~MyClientHandler();
};


#endif //PROJECT2_MYCLIENTHANDLER_H
