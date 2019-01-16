//
// Created by alexander on 1/16/19.
//

#ifndef PROJECT2_SEARCHSOLVER_H
#define PROJECT2_SEARCHSOLVER_H

#include "Solver.h"
#include "MatrixSearchable.h"
#include "BestFirstSearch.h"
#include <string>

#include <vector>

#define ERROR_CODE "-1"

using namespace std;

class SearchSolver : public Solver<string, vector<vector<string>>> {
public:
    string solve(vector<vector<string>> problem);

    ~SearchSolver();
};


#endif //PROJECT2_SEARCHSOLVER_H
