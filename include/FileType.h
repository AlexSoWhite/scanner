//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_FILETYPE_H
#define SCAN_UTIL_FILETYPE_H

#include <regex>
#include "Pattern.h"

// класс, объектами которого являются типы файлов.
// содержит:
//     тип файла (расширение),
//     регулярное выражение типа regex(".js"),
//     список подозрительных строк, встречающихся в данном типе файла
class FileType {
    int fileType;
    Pattern fileTypeRegex;
    std::vector<Pattern> suspiciousStrings;
public:
    FileType(int fileType, Pattern fileTypeRegex, const std::vector<Pattern> & susStrings);

    const Pattern &getFileTypeRegex() const;

    const std::vector<Pattern> &getSuspiciousStrings() const;

    int getFileType() const;
};

#endif //SCAN_UTIL_FILETYPE_H
