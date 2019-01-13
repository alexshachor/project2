//
// Created by avi on 1/13/19.
//

#ifndef PROJECT2_SEARCHER_H
#define PROJECT2_SEARCHER_H

#include "ISearcher.h"
#include <vector>

template<class Solution, class T>
class Searcher : public ISearcher<Solution, T> {
private:
    int nodesNumber;
    std::vector<State<T> *> open;
public:
    Searcher() {
        this->nodesNumber = 0;
    }
    State<T>* popOpenList() {
        this->nodesNumber++;
        return open.
    }
    virtual Solution search(Searchable<T> *searchable) = 0;
};

#endif //PROJECT2_SEARCHER_H
