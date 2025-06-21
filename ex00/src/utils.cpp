#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<std::string> split(const std::string &inputString, const char delimiters) {
    std::vector<std::string> result;
    unsigned long startPos = 0;
    unsigned long endPos;

    while ((endPos = inputString.find_first_of(delimiters, startPos)) != std::string::npos) {
        if (endPos != startPos) {
            result.push_back(inputString.substr(startPos, endPos - startPos));
        }
        startPos = endPos + 1;
    }

    if (startPos != inputString.length()) {
        result.push_back(inputString.substr(startPos));
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