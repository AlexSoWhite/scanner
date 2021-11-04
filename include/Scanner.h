//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_SCANNER_H
#define SCAN_UTIL_SCANNER_H

#include <regex>
#include "Pattern.h"
#include "ResultTypes.h"

// сканнер, который читает и сканирует определенный файл.
class Scanner {
public:
    Scanner() = default;
    static ResultTypes scan(
                const std::string& fileName,
                const std::vector<Pattern>& suspiciousStrings
            ); // сканирование файла на предмет наличия подозрительных строк
};

#endif //SCAN_UTIL_SCANNER_H
