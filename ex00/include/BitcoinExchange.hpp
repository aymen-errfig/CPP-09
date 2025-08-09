//
// Created by joe on 6/14/25.
//

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <map>
#include "DateTime.hpp"
#include <fstream>
#include <cstdlib>

#define MAX_VAL 1000

class DateTime;

class BitcoinExchange {
private:
    std::map<DateTime, double> exchange_data;
public:
    BitcoinExchange();

    void MatchClosestExchange(const std::string &date, const std::string &value) const;

    void ExchangeRate(const std::string &input_file) const;

    virtual ~BitcoinExchange();
};


#endif //BITCOINEXCHANGE_H