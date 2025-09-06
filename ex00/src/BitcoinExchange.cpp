//
// Created by joe on 6/14/25.
//

#include "../include/BitcoinExchange.hpp"

#include <algorithm>
#include <sys/stat.h>

BitcoinExchange::BitcoinExchange()
{
    std::string buff;
    std::map<size_t, std::string> tmp;

    std::ifstream dataStream("data.csv");
    if (!dataStream.is_open())
        throw std::runtime_error("Error opening file");

    std::getline(dataStream, buff);
    while (!dataStream.eof())
    {
        std::getline(dataStream, buff);
        tmp = split(trim(buff), ',');
        if (tmp.size() == 2)
            exchange_data[DateTime(tmp[0])] = atof(tmp[1].c_str());
    }
}

void BitcoinExchange::MatchClosestExchange(const std::string &date, const std::string &value) const
{
    try
    {
        const DateTime inputDate(date);
        const double inputValue = atof(value.c_str());
        if (inputValue < 0)
            throw std::runtime_error("Error: not a positive number.");
        if (inputValue > MAX_VAL)
            throw std::runtime_error("Error: too large a number.");

        std::map<DateTime, double>::const_iterator it = exchange_data.lower_bound(inputDate);

        if (it->first.date_string != inputDate.date_string)
        {
            if (it == exchange_data.begin())
            {
                throw std::runtime_error("No earlier exchange rate available for: " + inputDate.date_string);
            }
            --it;
        }
        const double rate = it->second;
        const double result = inputValue * rate;

        std::cout << inputDate.date_string
                  << " => " << inputValue << " = " << result << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::ExchangeRate(const std::string &input_file) const
{
    std::string buff;

    struct stat sb;

    if (stat(input_file.c_str(), &sb) == 0)
    {
        if (S_ISDIR(sb.st_mode))
            throw std::runtime_error("Error this is a directory");
    }
    std::ifstream inputStream(input_file.c_str());
    if (!inputStream.is_open())
        throw std::runtime_error("Error opening input file");

    std::getline(inputStream, buff);
    if (buff != "date | value")
        throw std::runtime_error("Error: file must start with 'date | value'");
    while (!inputStream.eof())
    {
        std::getline(inputStream, buff);
        std::map<size_t, std::string> tmp = split(trim(buff), '|');
        try
        {
            if (tmp.size() == 2)
                MatchClosestExchange(trim(tmp[0]), trim(tmp[1]));
            else
                throw std::runtime_error("Error: bad input ==> " + buff);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }
}
