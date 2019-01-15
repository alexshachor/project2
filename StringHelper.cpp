//
// Created by alexander on 1/15/19.
//

#include "StringHelper.h"

std::vector<std::string> StringHelper::splitByStr(std::string stringToSplit, std::string delimiter) {
    std::vector<std::string> splittedString;
    int startIndex = 0;
    int endIndex = 0;
    while ((endIndex = stringToSplit.find(delimiter, startIndex)) < stringToSplit.size()) {
        std::string val = stringToSplit.substr(startIndex, endIndex - startIndex);
        splittedString.push_back(val);
        startIndex = endIndex + delimiter.size();
    }
    if (startIndex < stringToSplit.size()) {
        std::string val = stringToSplit.substr(startIndex);
        splittedString.push_back(val);
    }
    return splittedString;
}

std::string StringHelper::getSubStringBeforeStr(std::string line, std::string str, int startPos) {
    std::string result;
    if (!str.empty()) {
        //find the position of str in string line
        int pos = line.find(str);
        //if the position is in the string range => str has found
        if (pos <= line.size()) {
            result = line.substr(startPos, pos);
        }
    }
    return result;
}