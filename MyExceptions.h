//
// Created by alexander on 1/14/19.
//

#ifndef PROJECT2_MYEXCEPTIONS_H
#define PROJECT2_MYEXCEPTIONS_H

#include <system_error>
#include <stdexcept>

class timeout_exception : public std::runtime_error {
public:
    timeout_exception(const char *msg) : std::runtime_error(msg) {}

    timeout_exception(std::string msg) : std::runtime_error(msg) {}
};

class illegal_state_exception : public std::logic_error {
public:
    illegal_state_exception(std::string msg) : std::logic_error(msg) {}
};


#endif //PROJECT2_MYEXCEPTIONS_H
