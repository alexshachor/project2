//
// Created by avi on 1/13/19.
//

#ifndef PROJECT2_SEARCHER_H
#define PROJECT2_SEARCHER_H

#include "ISearcher.h"
#include <vector>
#include <queue>

template<class Solution, class T>
class Searcher : public ISearcher<Solution, T> {
private:
    int evaluatedNodes;
    std::priority_queue<State<T> *> open;
public:
    Searcher() {
        this->evaluatedNodes = 0;
    }

    void addToOpenList(State<T> *newState) {
        this->open.push(newState);
    }

    State<T> *popOpenList() {
        this->evaluatedNodes++;
        State<T> *ret = open.top();
        open.pop();
        return ret;
    }

    long OpenListSize() {
        return open.size();
    }

    int getNumberNodesEvaluated() {
        return evaluatedNodes;;
    }

    virtual Solution search(Searchable<T> *searchable) = 0;
};

#endif //PROJECT2_SEARCHER_H
