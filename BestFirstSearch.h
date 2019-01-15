//
// Created by avi on 1/14/19.
//

#ifndef PROJECT2_BFSSEARCH_H
#define PROJECT2_BFSSEARCH_H

#include "Searcher.h"
#include <unordered_set>

template<class Solution, class T>
class BestFirstSearch : public Searcher<Solution, T> {

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
            result += it->getCost();
        }

        return result;
    }

public:


    Solution search(Searchable<T> *searchable) {

        addToOpenList(searchable->getInitialState());
        std::unordered_set<State<T> *, StateHashFunction<T> > closed;
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
                    vecIt->setCost += state->getCost();
                    addToOpenList(vecIt);
                } else {

                    //Otherwise, if this new path is better than previous one
                    //i. If it is not in OPEN add it to OPEN.
                    //ii. Otherwise, adjust its priority in OPEN
                }
            }
        }
    }

};


#endif //PROJECT2_BFSSEARCH_H
