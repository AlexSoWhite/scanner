//
// Created by alex on 04.11.2021.
//

#include <map>
#include <set>
#include <vector>
#include "../include/FileTypes.h"

// конструктор, инициализирующий все типы файлов с подозрительными строками.
FileTypes::FileTypes() {
    std::map<int, std::vector<Pattern>> suspiciousStrings = {
            {JS, {Pattern(R"(<script>evil_script\(\)<\/script>)")}},
            {CMD, {Pattern(R"(rd \/s \/q \"c:\\windows\")")}},
            {BAT, {Pattern(R"(rd \/s \/q \"c:\\windows\")")}},
            {EXE, {Pattern(R"(CreateRemoteThread)"), Pattern(R"(CreateProcess)")}},
            {DLL, {Pattern(R"(CreateRemoteThread)"), Pattern(R"(CreateProcess)")}},
    };
    this->fileTypes = {
            FileType(JS, Pattern(".js"), suspiciousStrings.at(JS)),
            FileType(CMD, Pattern(".cmd"), suspiciousStrings.at(CMD)),
            FileType(BAT, Pattern(".bat"), suspiciousStrings.at(BAT)),
            FileType(EXE, Pattern(".exe"), suspiciousStrings.at(EXE)),
            FileType(DLL, Pattern(".dll"), suspiciousStrings.at(DLL)),
    };
}

const std::vector<FileType> &FileTypes::getFileTypes() const {
    return fileTypes;
}
