//
// Created by alexander on 1/15/19.
//

#include "MatrixSearchable.h"

vector<vector<State<pair<int, int>> *>> getStatesMatrix(vector<vector<string>> matrix) {

}

State<pair<int, int>> *MatrixSearchable::getStateByPos(pair<int, int>) {

}


MatrixSearchable::MatrixSearchable(vector<vector<string>> matrixStr,
                                   vector<string> initState, vector<string> goalState) {
    this->matrix = getStatesMatrix(matrixStr);
}

vector<State<pair<int, int>> *> MatrixSearchable::getAllPossibleStates(State<pair<int, int>> *state) {

}

State<pair<int, int>> *MatrixSearchable::getInitialState() {
    return initialState;
}

bool MatrixSearchable::isGoalState(State<pair<int, int>> *state) {
    if (state == goalState) {
        return true;
    }
    return false;
}