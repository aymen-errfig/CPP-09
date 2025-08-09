//
// Created by joe on 6/21/25.
//

#ifndef CPP_09_DATETIME_H
#define CPP_09_DATETIME_H

#include <iostream>
#include <ctime>
#include "utils.hpp"
#include <map>
#include <cstdlib>
#include <climits>

class DateTime {

public:
    std::time_t timestamp;
    std::string date_string;
    DateTime(const std::string &date);
    bool operator<(const DateTime& other) const {
        if (timestamp != other.timestamp)
            return timestamp < other.timestamp;
        return  timestamp < other.timestamp;
    }
};


#endif //CPP_09_DATETIME_H
