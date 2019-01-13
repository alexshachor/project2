//
// Created by avi on 1/13/19.
//

#ifndef PROJECT2_ISEARCHER_H
#define PROJECT2_ISEARCHER_H

#include "Searchable.h"

template<class Solution, class T>
class ISearcher {
    virtual Solution search(Searchable<T> *searchable) = 0;

    virtual int getNumberNodesEvaluated() = 0;
};

#endif //PROJECT2_ISEARCHER_H
