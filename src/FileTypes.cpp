//
// Created by alex on 04.11.2021.
//

#include <map>
#include <set>
#include <vector>
#include "../include/FileTypes.h"

// конструктор, инициализирующий все типы файлов с подозрительными строками.
FileTypes::FileTypes() {
    std::map<int, std::vector<std::regex>> suspiciousStrings = {
            {JS, {std::regex(R"(<script>evil_script\(\)<\/script>)")}},
            {CMD, {std::regex(R"(rd \/s \/q \"c:\\windows\")")}},
            {BAT, {std::regex(R"(rd \/s \/q \"c:\\windows\")")}},
            {EXE, {std::regex(R"(CreateRemoteThread)"), std::regex(R"(CreateProcess)")}},
            {DLL, {std::regex(R"(CreateRemoteThread)"), std::regex(R"(CreateProcess)")}},
    };
    this->fileTypes = {
            FileType(JS, std::regex(".js"), suspiciousStrings.at(JS)),
            FileType(CMD, std::regex(".cmd"), suspiciousStrings.at(CMD)),
            FileType(BAT, std::regex(".bat"), suspiciousStrings.at(BAT)),
            FileType(EXE, std::regex(".exe"), suspiciousStrings.at(EXE)),
            FileType(DLL, std::regex(".dll"), suspiciousStrings.at(DLL)),
    };
}

const std::vector<FileType> &FileTypes::getFileTypes() const {
    return fileTypes;
}
