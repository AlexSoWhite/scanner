//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_FILETYPES_H
#define SCAN_UTIL_FILETYPES_H

#include "FileType.h"

// класс, объект которого хранит в себе набор типов файлов и подозрительных строк для каждого из них. предоставляет доступ к этим структурам.
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
    FileTypes(); // заполнение вектора fileTypes информацией из задания (собственно тип файла, расширение и подозрительные строки)
    const std::vector<FileType> &getFileTypes() const; // предоставление доступа к типам файлов
};


#endif //SCAN_UTIL_FILETYPES_H
