//
// Created by alex on 04.11.2021.
//

#include <set>
#include <utility>
#include "../include/FileType.h"

FileType::FileType(int fileType, std::regex fileTypeRegex, const std::vector<std::regex>& susStrings) {
    this->fileType = fileType;
    this->fileTypeRegex = std::move(fileTypeRegex);
    this->suspiciousStrings = susStrings;
}

const std::regex &FileType::getFileTypeRegex() const {
    return fileTypeRegex;
}

const std::vector<std::regex> &FileType::getSuspiciousStrings() const {
    return suspiciousStrings;
}

int FileType::getFileType() const {
    return fileType;
}
