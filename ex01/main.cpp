//
// Created by joe on 6/27/25.
//

#include <iostream>
#include <stack>
#include "RPN.hpp"

int main(int ac, char *av[]) {
    std::stack<int> stack;
    if (ac == 2) {
        try {
            RPN rpn(av[1]);
            std::cout << rpn.getNumbersStack().top() << "\n";
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
    else {
        std::cout << "need 1 argument";
        return 1;
    }
    return 0;
}