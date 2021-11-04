//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_SCANNER_H
#define SCAN_UTIL_SCANNER_H

#include <regex>
#include "Pattern.h"
#include "ResultTypes.h"

// класс, объект которого читает и сканирует определенный файл.
class Scanner {
public:
    Scanner() = default;
    ResultTypes scan(const std::string& fileName, const std::vector<Pattern>& suspiciousStrings);
};

#endif //SCAN_UTIL_SCANNER_H
