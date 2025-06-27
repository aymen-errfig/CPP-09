//
// Created by joe on 6/14/25.
//

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::string buff;
    std::vector<std::string> tmp;

    std::ifstream dataStream("data.csv");
    if (!dataStream.is_open())
        throw std::runtime_error("Error opening file");

    std::getline(dataStream, buff);
    while (!dataStream.eof()) {
        std::getline(dataStream, buff);
        tmp = split(trim(buff), ',');
        if (tmp.size() == 2)
            exchange_data[DateTime(tmp[0])] = atof(tmp[1].c_str());
    }
}

void BitcoinExchange::MatchClosestExchange(const std::string &date, const std::string &value) const {

        // Find the first exchange date > inputDate
        try {
            DateTime inputDate(date);
            double inputValue = atof(value.c_str());
            if (inputValue < 0 || inputValue > INT_MAX){
                std::cout << "invalid value for price" << std::endl;
                return;
            }
            std::map<DateTime, double>::const_iterator ex = exchange_data.upper_bound(inputDate);

            if (ex == exchange_data.begin()) {
                std::cout << "No earlier exchange rate available for: "
                          << inputDate.date_string << std::endl;
            }

            --ex; // Step back to get <= inputDate

            double rate = ex->second;
            double result = inputValue * rate;

            std::cout << inputDate.date_string
                      << " => " << inputValue << " = " << result << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << "\n";
        }
}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::ExchangeRate(const std::string &input_file) const {
    std::string buff;
    std::vector<std::string> tmp;

    std::ifstream inputStream(input_file.c_str());
    if (!inputStream.is_open())
        throw std::runtime_error("Error opening input file");

    while (!inputStream.eof()) {
        std::getline(inputStream, buff);
        tmp = split(trim(buff), '|');
        if (tmp.size() == 2)
            MatchClosestExchange(trim(tmp[0]), trim(tmp[1]));
    }
}
