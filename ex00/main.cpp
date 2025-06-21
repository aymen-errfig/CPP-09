//
// Created by joe on 6/14/25.
//

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "include/BitcoinExchange.hpp"

int main(int ac, char *av[]){
    if (ac != 2) {
        std::cout << "need file as input" << "\n";
        return 1;
    }

    try {
        const BitcoinExchange exchanger = BitcoinExchange();
        exchanger.ExchangeRate(av[1]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}