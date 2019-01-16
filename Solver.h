//
// Created by avi on 1/9/19.
//

#ifndef PROJECT2_SOLVER_H
#define PROJECT2_SOLVER_H

template<class S, class P>
class Solver {
public:
    virtual S solve(P problem) = 0;
};

#endif //PROJECT2_SOLVER_H
