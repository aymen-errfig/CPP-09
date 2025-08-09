//
// Created by aerrfig on 05/07/25.
//


#include <algorithm>
#include <iostream>
#include <cmath>
#include <deque>
#include <climits>
#include <cerrno>
#include "PmergeMe.hpp"


int main(const int ac, char *av[]) {
    if (ac < 2) {
        std::cout << "need at least 2 argument" << std::endl;
        return 1;
    }
    std::cout << "====================== std::deque =====================" << std::endl;
    {
        const clock_t start = clock();
        char *end;
        try {
            deq numbers;
            for (int i = 1; i < ac; ++i) {
                const long num = strtol(av[i], &end, 10);
                if (num < 0 || num > INT_MAX || av[i] == end || errno == ERANGE)
                    throw std::runtime_error("invalid number detected");
                if (std::find(numbers.begin(), numbers.end(), static_cast<int>(num)) != numbers.end())
                    throw std::runtime_error("duplicated numbers detected");
                numbers.push_back(static_cast<int>(num));
            }
            std::cout << "Before : ";
            printDeq(numbers);
            deq result = fordJohnsonDeq(numbers);
            std::cout << "After : ";
            printDeq(result);
            std::cout << "Time to process a range of  : " << numbers.size() << " elements with std::deque " << (static_cast<double>(clock()- start)) / static_cast<double>(CLOCKS_PER_SEC) << " us" << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "====================== std::vector =====================" << std::endl;
    {
        const clock_t start = clock();
        char *end;
        try {
            vec numbers;
            for (int i = 1; i < ac; ++i) {
                const long num = strtol(av[i], &end, 10);
                if (num < 0 || num > INT_MAX || av[i] == end || errno == ERANGE)
                    throw std::runtime_error("invalid number detected");
                if (std::find(numbers.begin(), numbers.end(), static_cast<int>(num)) != numbers.end())
                    throw std::runtime_error("duplicated numbers detected");
                numbers.push_back(static_cast<int>(num));
            }
            std::cout << "Before : ";
            printVec(numbers);
            vec result = fordJohnsonVec(numbers);
            std::cout << "After : ";
            printVec(result);
            std::cout << "Time to process a range of  : " << numbers.size() << " elements with std::deque " << (static_cast<double>(clock()- start)) / static_cast<double>(CLOCKS_PER_SEC) << " us" << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
