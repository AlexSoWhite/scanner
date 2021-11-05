//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_FILETYPE_H
#define SCAN_UTIL_FILETYPE_H

#include <regex>

// класс, объектами которого являются типы файлов.
class FileType {
    int fileType; // тип файла (расширение)
    std::regex fileTypeRegex; // регулярное выражение типа regex(".js")
    std::vector<std::regex> suspiciousStrings; // список подозрительных строк, встречающихся в данном типе файла
public:
    FileType(int fileType, std::regex fileTypeRegex, const std::vector<std::regex> & susStrings);
    const std::regex &getFileTypeRegex() const;
    const std::vector<std::regex> &getSuspiciousStrings() const;
    int getFileType() const;
};

#endif //SCAN_UTIL_FILETYPE_H
