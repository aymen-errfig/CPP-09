#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

std::map<size_t, std::string> split(const std::string &inputString, const char delimiters) {
    std::map<size_t, std::string> result;
    unsigned long startPos = 0;
    unsigned long endPos;
    size_t index = 0;

    while ((endPos = inputString.find_first_of(delimiters, startPos)) != std::string::npos) {
        if (endPos != startPos) {
            result[index++] = inputString.substr(startPos, endPos - startPos);
        }
        startPos = endPos + 1;
    }

    if (startPos != inputString.length()) {
        result[index] = inputString.substr(startPos);
    }
    return result;
}

std::string trim(const std::string &str) {
    size_t start = 0;
    size_t end = str.length() - 1;

    while (start <= end && std::isspace(str[start])) {
        ++start;
    }
    while (end >= start && std::isspace(str[end])) {
        --end;
    }
    return str.substr(start, end - start + 1);
}