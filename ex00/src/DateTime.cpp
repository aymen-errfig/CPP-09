//
// Created by joe on 6/21/25.
//

#include "../include/DateTime.hpp"

DateTime::DateTime(const std::string &date) {
    date_string = date;
    struct tm time_info;
    std::vector<std::string> tmp;
    tmp = split(trim(date), '-');

    if (date.size() < 3)
        return;
    long year = atol(tmp[0].c_str());
    long month = atol(tmp[1].c_str());
    long day = atol(tmp[2].c_str());

    time_info.tm_isdst = -1;
    time_info.tm_sec = 0;
    time_info.tm_min = 0;
    time_info.tm_hour = 0;
    time_info.tm_mday = day;
    time_info.tm_mon = month - 1;
    time_info.tm_year = year - 1900;

    timestamp = std::mktime(&time_info);

    if (timestamp < 0)
        throw std::runtime_error("invalid date");
}