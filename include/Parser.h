//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_PARSER_H
#define SCAN_UTIL_PARSER_H

#include <vector>

// класс, объект которого получает и хранит массив имен файлов в директории. не делает ничего с конкретным файлом.
class Parser {
    std::vector<std::string> fileNames;
public:

    Parser();

    Parser & parse(const std::string & directoryName);

    std::vector<std::string> getFileNames();

    void printFileNames();
};


#endif //SCAN_UTIL_PARSER_H
