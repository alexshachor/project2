//
// Created by alexander on 1/15/19.
//

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"

class FileCacheManager : public CacheManager {

    bool hasSolution(std::string problem);

    std::string getSolution(std::string problem);

    void saveSolution(std::string problem, std::string solution);
};


#endif //PROJECT2_FILECACHEMANAGER_H
