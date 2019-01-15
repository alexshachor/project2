//
// Created by alexander on 1/15/19.
//

#ifndef PROJECT2_STRINGHELPER_H
#define PROJECT2_STRINGHELPER_H

#include <string>
#include <vector>

class StringHelper {
public:
    std::vector<std::string> splitByStr(std::string stringToSplit, std::string delimiter);

    std::string getSubStringBeforeStr(std::string line, std::string str, int startPos = 0);
};


#endif //PROJECT2_STRINGHELPER_H
