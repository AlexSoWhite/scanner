//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_DISPATCHER_H
#define SCAN_UTIL_DISPATCHER_H

#include "FileTypes.h"
#include "AnalysisResult.h"

// класс, объект которого решает, как просканировать файл с помощью Scanner и обрабатывает результат
class Dispatcher {
    FileTypes fileTypes; // это поле хранит типы файлов со всеми данными
public:
    Dispatcher(); // инициализация fileTypes через дефолтный конструктор FileTypes()
    void start(const std::string& fileName, AnalysisResult &ar); // запуск сканнеров и обработка результатов
};

#endif //SCAN_UTIL_DISPATCHER_H
