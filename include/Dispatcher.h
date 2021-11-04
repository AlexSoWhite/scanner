//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_DISPATCHER_H
#define SCAN_UTIL_DISPATCHER_H

#include "FileType.h"
#include "FileTypes.h"
#include "AnalysisResult.h"

//класс, объект которого принимает на вход имя файла и решает, как его просканировать с помощью Scanner.
class Dispatcher {
    FileTypes fileTypes;
public:
    Dispatcher();
    void start(const std::string& fileName, AnalysisResult &ar);
};

#endif //SCAN_UTIL_DISPATCHER_H
