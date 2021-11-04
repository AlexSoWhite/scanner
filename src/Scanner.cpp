//
// Created by alex on 04.11.2021.
//

#include <fstream>
#include <iostream>
#include "../include/Scanner.h"

ResultTypes Scanner::scan(const std::string& fileName, const std::vector<Pattern>& suspiciousStrings) {
    std::ifstream fin;
    fin.open(fileName);
    if (!fin.is_open()) {
        return ResultTypes::ERROR;
    }
    std::string currentString;
    while (!fin.eof()) {
        getline(fin, currentString);
        for (const Pattern & pattern : suspiciousStrings) {
            if (std::regex_search(currentString, pattern.reg)) {
                // std::cout<<fileName<<" "<<currentString<<std::endl;
                fin.close();
                return ResultTypes::DETECTED;
            }
        }
    }
    fin.close();
    return ResultTypes::UNDETECTED;
}
