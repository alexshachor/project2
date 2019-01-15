//
// Created by alexander on 1/15/19.
//

#ifndef PROJECT2_MATRIXSEARCHABLE_H
#define PROJECT2_MATRIXSEARCHABLE_H

#include "Searchable.h"
#include <string>
#include <algorithm>

#define BLOCKED_COST_VALUE -1

using namespace std;

class MatrixSearchable : public Searchable<pair<int, int>> {
private:

    vector<vector<State<pair<int, int>> *>> matrix;
    State<pair<int, int>> *initialState;
    State<pair<int, int>> *goalState;

    State<pair<int, int>> *getStateByPos(pair<int, int> pos);

public:
    MatrixSearchable(const vector<vector<string>>
                     &matrixStr, vector<string>
                     initState, vector<string>
                     goalState);

    State<pair<int, int>> *getInitialState();

    bool isGoalState(State<pair<int, int>> *state);

    vector<State<pair<int, int>> *> getAllPossibleStates(State<pair<int, int>> *state);

    ~MatrixSearchable();
};


#endif //PROJECT2_MATRIXSEARCHABLE_H
