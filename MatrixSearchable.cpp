//
// Created by alexander on 1/15/19.
//

#include "MatrixSearchable.h"

pair<int, int> getPairPosByStrVec(vector<string> vecStr) {
    pair<int, int> result(stoi(vecStr[0]), stoi(vecStr[1]));
    return result;
}

vector<vector<State<pair<int, int>> *>> getStatesMatrix(const vector<vector<string>> &matrix) {
    vector<vector<State<pair<int, int>> *>> result;
    for (int i = 0; i < matrix.size(); ++i) {
        vector<State<pair<int, int>> *> vecJ;
        for (int j = 0; j < matrix[i].size(); ++j) {
            pair<int, int> pos(i, j);
            double cost = stod(matrix[i][j]);
            vecJ.push_back(new State<pair<int, int>>(pos, cost, nullptr));
        }
        result.push_back(vecJ);
    }
    return result;
}

State<pair<int, int>> *MatrixSearchable::getStateByPos(pair<int, int> pos) {
    return this->matrix.at(pos.first).at(pos.second);
}


MatrixSearchable::MatrixSearchable(const vector<vector<string>> &matrixStr,
                                   vector<string> initState, vector<string> goalState) {
    this->matrix = getStatesMatrix(matrixStr);
    pair<int, int> initPos = getPairPosByStrVec(initState);
    pair<int, int> goalPos = getPairPosByStrVec(goalState);
    this->initialState = getStateByPos(initPos);
    this->goalState = getStateByPos(goalPos);
}

vector<State<pair<int, int>> *> MatrixSearchable::getAllPossibleStates(State<pair<int, int>> *state) {
    vector<State<pair<int, int>> *> result;
    pair<int, int> pos = state->getState();
    int x = pos.first, y = pos.second;
    if (!matrix.empty()) {
        int rowLimit = matrix.size() - 1;
        int colLimit = matrix[0].size() - 1;
        for (int i = max(0, x - 1); i <= min(x + 1, rowLimit); ++i) {
            for (int j = max(0, y - 1); j <= min(y + 1, colLimit); ++j) {
                if ((i != x && j == y) || (j != y && i == x)) {
                    if (matrix[i][j]->getCost() != BLOCKED_COST_VALUE) {
                        result.push_back(matrix[i][j]);
                    }
                }
            }
        }
    }
    return result;
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

MatrixSearchable::~MatrixSearchable() {
    int rows = matrix.size();
    for (int i = 0; i < rows; ++i) {
        int columns = matrix[i].size();
        for (int j = 0; j < columns; ++j) {
            delete matrix[i][j];
        }
    }
}