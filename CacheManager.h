//
// Created by alexander on 1/10/19.
//

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H

template<class P, class S>
class CacheManager {
public:
    virtual bool hasSolution(P problem) = 0;

    virtual S getSolution(P problem) = 0;

    virtual void saveSolution(P problem, S solution) = 0;
};


#endif //PROJECT2_CACHEMANAGER_H
