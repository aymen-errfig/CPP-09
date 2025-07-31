//
// Created by aerrfig on 31/07/25.
//

#ifndef PMERGEME_H
#define PMERGEME_H

#include <deque>
#include <cmath>

typedef std::deque<int>::iterator iterator;
typedef std::deque<int> deq;


deq fordJohnsonDeq(deq &input);

deq jacobstahlSeqDeq(const size_t n);

int jacobstahlSequence(const int n);

void printDeq(deq &d);

#endif //PMERGEME_H
