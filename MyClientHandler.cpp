//
// Created by alexander on 1/10/19.
//

#include "MyClientHandler.h"

MyClientHandler::MyClientHandler(Solver<string, vector<vector<string>>> *solver, CacheManager *cacheManager) {
    this->solver = solver;
    //this->cacheManager = cacheManager;
}

void MyClientHandler::handleClient(int sockfd) {
    posix_sockets::TcpClient client(sockfd);
    StringHelper stringHelper;

    string output = client.readUntil(END_CONVERSATION_WORD);
    std::vector<string> lines = stringHelper.splitByStr(output, NEW_LINE);
    std::vector<std::vector<string>> matrix;
    for (int i = 0; i < lines.size(); ++i) {
        vector<string> values = stringHelper.splitByStr(lines[i], VALUES_DELIMETER);
        matrix.push_back(values);
    }

    string result = solver->solve(matrix);
    client.sendMessage(result);
}

MyClientHandler::~MyClientHandler() {
    delete this->solver;
    //delete this->cacheManager
}