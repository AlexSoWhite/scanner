//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_FILETYPES_H
#define SCAN_UTIL_FILETYPES_H

#include "FileType.h"

// класс, хранящий набор типов файлов и подозрительных строк для каждого из них. также предоставляет доступ к этим структурам.
class FileTypes {
    std::vector<FileType> fileTypes;
public:
    enum {
        JS,
        CMD,
        BAT,
        EXE,
        DLL
    };
    FileTypes();

    const std::vector<FileType> &getFileTypes() const;
};


#endif //SCAN_UTIL_FILETYPES_H
