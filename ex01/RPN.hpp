//
// Created by joe on 6/27/25.
//

#ifndef CPP_09_RPN_H
#define CPP_09_RPN_H

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN {
    std::stack<int> rnp_stack;
public:
    RPN(const std::string &str);
    RPN &operator=(const RPN &other);
    RPN(const RPN &other);
    const std::stack<int> &getNumbersStack() const;
    ~RPN();
};


#endif //CPP_09_RPN_H
