//
// Created by alex on 04.11.2021.
//

#include <string>
#include <set>
#include <utility>
#include "../include/FileType.h"
#include "../include/FileTypes.h"

FileType::FileType(int fileType, Pattern fileTypeRegex, const std::vector<Pattern>& susStrings) {
    this->fileType = fileType;
    this->fileTypeRegex = std::move(fileTypeRegex);
    this->suspiciousStrings = susStrings;
}

const Pattern &FileType::getFileTypeRegex() const {
    return fileTypeRegex;
}

const std::vector<Pattern> &FileType::getSuspiciousStrings() const {
    return suspiciousStrings;
}

int FileType::getFileType() const {
    return fileType;
}
