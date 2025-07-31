//
// Created by aerrfig on 31/07/25.
//

#include "PmergeMe.hpp"

#include <iostream>

int jacobstahlSequence(const int n) {
    return static_cast<int>((pow(2, n) - pow(-1, n)) / 3);
}

deq fordJohnsonDeq(deq &input) {
    deq main;
    deq pend;

    if (input.size() == 1) {
        return input;
    }
    for (iterator it = input.begin(); it != input.end(); ) {
        iterator temp = it;
        ++temp;
        if (temp == input.end()) {
            main.push_back(*it);
            break;
        }
        int first = *it;
        int second = *temp;
        main.push_back(std::max(first, second));
        pend.push_back(std::min(first, second));
        std::advance(it, 2);
    }

    const deq nums = fordJohnsonDeq(main);
    const deq order_list = jacobstahlSeqDeq(pend.size());


    deq result = nums;
    for (size_t i = 0; i < pend.size(); ++i) {
        int current = pend[order_list[i]];
        iterator pos = std::lower_bound(result.begin(), result.end(), current);
        result.insert(pos, current);
    }
    return result;
}

deq jacobstahlSeqDeq(const size_t n) {
    deq order;
    std::deque<bool> used(n, false);

    for (size_t i = 0; i < n; ++i) {
        int jacob_num = jacobstahlSequence(i);
        if (static_cast<size_t>(jacob_num) < n && used[jacob_num] == false) {
            order.push_back(jacob_num);
            used[jacob_num] = true;
        }
    }
    for (size_t i = 0; i < n; ++i) {
        if (used[i] == false) {
            order.push_back(i);
        }
    }
    return order;
}

void printDeq(deq &d) {
    for (iterator it = d.begin(); it != d.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}