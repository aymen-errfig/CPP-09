#ifndef PMERGEME_H
#define PMERGEME_H

#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>


typedef std::deque<int>::iterator iterator;
typedef std::deque<int> deq;

typedef std::vector<int> vec;
typedef std::vector<int>::iterator viterator;


deq fordJohnsonDeq(deq &input);

deq jacobstahlSeqDeq(const size_t n);

int jacobstahlSequence(const int n);

void printDeq(deq &d);

vec fordJohnsonVec(vec& input);

std::vector<size_t> jacobstahlSeqVec(size_t n);

void printVec(vec& v);

#endif //PMERGEME_H