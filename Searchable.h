//
// Created by avi on 1/13/19.
//

#ifndef PROJECT2_SEARCHABLE_H
#define PROJECT2_SEARCHABLE_H

#include "State.h"
#include <vector>

template<class T>
class Searchable {
    virtual State<T> *getInitialState() = 0;

    virtual bool isGoalState(State<T> *state) = 0;

    virtual std::vector<State<T> *> getAllPossibleStates(State<T> *state) = 0;
};

#endif //PROJECT2_SEARCHABLE_H
