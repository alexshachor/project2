//
// Created by avi on 1/14/19.
//

#ifndef PROJECT2_BFSSEARCH_H
#define PROJECT2_BFSSEARCH_H

#include "Searcher.h"
#include <unordered_set>

template<class Solution, class T>
class BestFirstSearch : public Searcher<Solution, T> {

public:

    Solution search(Searchable<T> *searchable) {

        addToOpenList(searchable->getInitialState());
        std::unordered_set<State<T> *, StateHashFunction<T> > closed;
        while (OpenListSize() > 0) {
            State<T> *state = popOpenList();
            closed.insert(state);  //TODO: ( ,stateHashFunction)?

        }
    }

};


#endif //PROJECT2_BFSSEARCH_H
