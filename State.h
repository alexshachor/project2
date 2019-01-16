//
// Created by avi on 1/13/19.
//

#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

#include <cstddef>

template<class T>
class State {
private:
    T state;
    double cost;
    State<T> *cameFrom;
public:
    State(T state, double cost, State<T> *cameFrom) {
        this->state = state;
        this->cost = cost;
        this->cameFrom = cameFrom;
    }

    T getState() {
        return this->state;
    }

    double getCost() {
        return this->cost;
    }

    State<T> *getCameFrom() {
        return this->cameFrom;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T> *cameFrom) {
        this->cameFrom = cameFrom;
    }

    bool operator==(const State<T> &other) const {
        return (this->getState() == other.getState());
    }

    bool operator<(const State<T> &other) const {
        return !(this->cost > other.cost);
    }

};

template<class T>
class StateHashFunction {
public:
    size_t operator()(const State<T> &state) const {
        return (size_t) (state).getCost();
    }
};


#endif //PROJECT2_STATE_H
