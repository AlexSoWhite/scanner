//
// Created by alex on 04.11.2021.
//

#include <fstream>
#include "../include/Scanner.h"

ResultTypes Scanner::scan(const std::string& fileName, const std::vector<Pattern>& suspiciousStrings) {

    // пробуем открыть файл
    std::ifstream fin;
    fin.open(fileName);

    // файл не открылся - возвращаем ошибку
    if (!fin.is_open()) {
        return ResultTypes::ERROR;
    }

    // если файл открылся, читаем его по строкам и ищем в нем подозрительные строчки
    std::string currentString;
    while (!fin.eof()) {
        getline(fin, currentString);
        for (const Pattern & pattern : suspiciousStrings) {
            if (std::regex_search(currentString, pattern.reg)) {
                // подозрительная строка найдена. не забываем закрыть файл
                fin.close();
                return ResultTypes::DETECTED;
            }
        }
    }

    // если дошло сюда, значит, мы ничего не нашли
    fin.close();
    return ResultTypes::UNDETECTED;
}
