//
// Created by alexander on 1/16/19.
//

#include "SearchSolver.h"

string SearchSolver::solve(vector<vector<string>> problem) {
    //get goal state
    vector<string> goalStr = problem.back();
    problem.pop_back();
    //get init state
    vector<string> initStr = problem.back();
    problem.pop_back();
    MatrixSearchable *matrixSearchable = new MatrixSearchable(problem, initStr, goalStr);
    BestFirstSearch<vector<State<pair<int, int>> *>, pair<int, int>> *bestFirstSearch =
            new BestFirstSearch<vector<State<pair<int, int>> *>, pair<int, int>>();
    //get the solution
    vector<State<pair<int, int>> *> solution = bestFirstSearch->search(matrixSearchable);
    delete matrixSearchable;
    delete bestFirstSearch;

    if (solution.empty()) {
        return ERROR_CODE;
    }
    //transform the solution into directions(left,right etc..)
    for (int i = 0; i < solution.size() - 1; ++i) {

    }


}

SearchSolver::~SearchSolver() {

}