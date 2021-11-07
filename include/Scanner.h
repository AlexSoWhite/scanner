//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_SCANNER_H
#define SCAN_UTIL_SCANNER_H

#include <regex>

// сканер, который читает и сканирует определенный файл.
class Scanner {
public:
    enum Result {
        DETECTED,
        UNDETECTED,
        ERROR
    };
    Scanner() = default;
    static Result scan(
                const std::string& fileName,
                const std::vector<std::regex>& suspiciousStrings
            ); // сканирование файла на предмет наличия подозрительных строк
};

#endif //SCAN_UTIL_SCANNER_H
