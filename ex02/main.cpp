//
// Created by aerrfig on 05/07/25.
//


#include <algorithm>
#include <iostream>
#include <list>
#include <cmath>
#include <deque>

typedef std::pair<int, int> Pair;
typedef std::deque<int>::iterator iterator;
typedef std::deque<int> list;

int jacobstahlSequence(const int n) {
    return static_cast<int>((pow(2, n) - pow(-1, n)) / 3);
}

list jacobstahl(const size_t n) {
    list order;
    std::deque<bool> used(n, false);

    for (int i = 0; i < n; ++i) {
        int jacob_num = jacobstahlSequence(i);
        if (jacob_num < n && used[jacob_num] == false) {
            order.push_back(jacob_num);
            used[jacob_num] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == false) {
            order.push_back(i);
        }
    }
    return order;
}

list fordJohnson(list &input) {
    list main;
    list pend;

    if (input.size() == 1) {
        return input;
    }
    for (iterator it = input.begin(); it != input.end(); ++it) {
        if (std::next(it) == input.end()) {
            main.push_back(*it);
            break;
        }
        int first = *it;
        iterator next = std::next(it);
        int second = *next;
        ++it;
        main.push_back(std::max(first, second));
        pend.push_back(std::min(first, second));
    }

    const list nums = fordJohnson(main);
    const list order_list = jacobstahl(pend.size());


    list result = nums;
    for (size_t i = 0; i < pend.size(); ++i) {
        int current = pend[order_list[i]];
        iterator pos = std::lower_bound(result.begin(), result.end(), current);
        result.insert(pos, current);
    }
    return result;
}

int main() {
    list numbers{0, 2, 1, 3, 5, 4, -1};

    const list g = fordJohnson(numbers);
    for (const int k : g) {
        std::cout << k << " ";
    }
    std::cout << "\n";

    return 0;
}
