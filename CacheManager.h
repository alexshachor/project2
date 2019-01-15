//
// Created by alexander on 1/10/19.
//

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H

#include <string>

class CacheManager {
public:
    virtual bool hasSolution(std::string problem) = 0;

    virtual std::string getSolution(std::string problem) = 0;

    virtual void saveSolution(std::string problem, std::string solution) = 0;
};


#endif //PROJECT2_CACHEMANAGER_H
