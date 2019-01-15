//
// Created by avi on 1/13/19.
//

#ifndef PROJECT2_SEARCHER_H
#define PROJECT2_SEARCHER_H

#include "ISearcher.h"
#include "State.h"
#include <vector>
#include <queue>


template<class Solution, class T>
class Searcher : public ISearcher<Solution, T> {

private:
    int evaluatedNodes;
    std::priority_queue<State<T> *> open;

protected:
    void addToOpenList(State<T> *newState) {
        this->open.push(newState);
    }

    State<T> *popOpenList() {
        this->evaluatedNodes++;
        State<T> *ret = open.top();
        open.pop();
        return ret;
    }

    long openListSize() {
        return open.size();
    }

    bool isInOpenList(State<T> *state) {
        std::priority_queue<State<T> *> temp = open;
        while(!temp.empty()) {
            if (temp.top() == state) {
                return true;
            }
            temp.pop();
        }
        return false;
    }

    State<T>* getElementFromOpen(State<T>* state) {
        std::priority_queue<State<T> *> temp = open;
        if (isInOpenList(state)) {
            while(!temp.empty()) {
                if (temp.top() == state) {
                    return temp.top();
                }
                temp.pop();
            }
        }
        return nullptr;
    }

public:
    Searcher() {
        this->evaluatedNodes = 0;
    }

    int getNumberNodesEvaluated() {
        return evaluatedNodes;
    }

    virtual Solution search(Searchable<T> *searchable) = 0;
};

#endif //PROJECT2_SEARCHER_H
