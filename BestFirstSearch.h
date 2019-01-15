//
// Created by avi on 1/14/19.
//

#ifndef PROJECT2_BFSSEARCH_H
#define PROJECT2_BFSSEARCH_H

#include "Searcher.h"
#include <unordered_set>

template<class Solution, class T>
class BestFirstSearch : public Searcher<Solution, T> {

private:
    std::unordered_set<State<T> *, StateHashFunction<T> > closed;

    bool isInClosedList(State<T> *state) {
        if (closed.find(state) == closed.end()) {
            return false;
        }
        return true;
    }

    State<T> *getElementFromClosed(State<T> *state) {
        State<T> *result = nullptr;
        if (isInClosedList(state)) {
            result = closed.find(state);
        }
        return result;
    }

    std::vector<State<T> *> backTrace(State<T> *state) {

        std::vector<State<T> *> result;
        State<T> *temp = state;
        result.push_back(temp);

        while ((temp = temp->getCameFrom()) != nullptr) {
            result.push_back(temp);
        }

        return result;
    }

    long sumTrace(State<T> *state) {

        std::vector<State<T> *> trace = backTrace(state);
        long result = 0;

        typename std::vector<State<T> *>::iterator it;
        for (it = trace.begin(); it != trace.end(); it++) {
            if (it->getCameFrom() != nullptr) {
                result += it->getCost();
            }
        }

        return result;
    }

public:

    Solution search(Searchable<T> *searchable) {

        addToOpenList(searchable->getInitialState());

        while (openListSize() > 0) {
            State<T> *state = popOpenList();
            closed.insert(state);
            if (state == searchable->getIGoallState()) {
                return backTrace(state);
            }

            std::vector<State<T> *> succerssors =
                    searchable->getAllPossibleStates(state);
            typename std::vector<State<T> *>::iterator vecIt;
            for (vecIt = succerssors.begin(); vecIt != succerssors.end();
                 vecIt++) {
                if ((closed.find(vecIt) == closed.end()) &&
                    !isInOpenList(vecIt)) {
                    vecIt->setCameFrom(state);
                    addToOpenList(vecIt);
                } else {
                    State<T>* prev = getElementFromOpen(vecIt);
                    if (prev == nullptr) {
                        prev = getElementFromClosed(vecIt);
                    }
                    if (sumTrace(state) + vecIt->getCost() < sumTrace(prev)) {
                        vecIt->setCameFrom(state);
                        if (!isInOpenList(vecIt)) {
                            addToOpenList(vecIt);
                        }
                    }
                }
            }
        }
    }
};


#endif //PROJECT2_BFSSEARCH_H
