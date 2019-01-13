//
// Created by avi on 1/13/19.
//

#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

template <class T>
class State {
private:
    T state;
    double cost;
    State<T> cameFrom;
public:
    State(T state, double cost, State<T> cameFrom) {
        this->state = state;
        this->cost = cost;
        this->cameFrom= cameFrom;
    }

    T getState() {
        return this->state;
    }

    double getCost() {
        return this->cost;
    }

    State<T> getCameFrom() {
        return this->cameFrom;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T> cameFrom) {
        this->cameFrom = cameFrom;
    }
};


#endif //PROJECT2_STATE_H
