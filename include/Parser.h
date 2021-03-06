//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_PARSER_H
#define SCAN_UTIL_PARSER_H

#include <vector>

// Класс, объект которого получает и хранит массив имен файлов в директории. Не делает ничего с конкретным файлом.
class Parser {
    std::vector<std::string> fileNames;
public:
    Parser(); // создание пустого вектора
    void parse(const std::string & directoryName); // получение имен файлов в дирекотрии
    std::vector<std::string> getFileNames(); // предоставление доступа к именам файлов
};


#endif //SCAN_UTIL_PARSER_H
