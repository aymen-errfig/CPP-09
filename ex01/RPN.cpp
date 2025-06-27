//
// Created by joe on 6/27/25.
//

#include "RPN.hpp"

RPN::RPN(const std::string &str) {
    std::istringstream iss(str);
    std::string token;
    while (iss >> token) {
        if ((token == "+") | (token == "-") | (token == "*") | (token == "/")) {
            if (rnp_stack.size() < 2)
                throw std::runtime_error("no numbers in stack");
            int a = rnp_stack.top();
            rnp_stack.pop();
            int b = rnp_stack.top();
            rnp_stack.pop();
            switch (token[0]) {
                case '+':
                    rnp_stack.push(a + b);
                    break;
                case '-':
                    rnp_stack.push(b - a);
                    break;
                case '*':
                    rnp_stack.push(a * b);
                    break;
                case '/':
                    rnp_stack.push(a / b);
                    break;
                default:
                    throw std::runtime_error("invalid token");
            }
        } else {
            if (token.size() > 1 || !std::isdigit(token[0]))
                throw std::runtime_error("invalid token");
            int num = token[0] - '0';
            rnp_stack.push(num);
        }
    }
}

RPN::RPN(const RPN &other) {
    this->rnp_stack = other.rnp_stack;
}

RPN &RPN::operator=(const RPN &other) {
    this->rnp_stack = other.rnp_stack;
    return *this;
}

const std::stack<int> &RPN::getNumbersStack() const {
    return rnp_stack;
}

RPN::~RPN() {}
