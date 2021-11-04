//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_ANALYSISRESULT_H
#define SCAN_UTIL_ANALYSISRESULT_H

#include <ctime>

// класс, объект которого хранит в себе результаты анализа, в том числе время
class AnalysisResult {
    unsigned long processedFiles;
    int jsDetects;
    int cmdDetects;
    int exeDetects;
    int errors;
    clock_t startTime{};
    clock_t endTime{};
public:
    AnalysisResult();
    void print() const;

    void setProcessedFiles(unsigned long filesAmount) { this->processedFiles = filesAmount; };

    void increaseJsDetects() { ++this->jsDetects; };

    void increaseCmdDetects() { ++this->cmdDetects; };

    void increaseExeDetects() { ++this->exeDetects; };

    void increaseErrors() { ++this->errors; };

    void setStartTime(clock_t time) { this->startTime = time; };

    void setEndTime(clock_t time) { this->endTime = time; };
};

#endif //SCAN_UTIL_ANALYSISRESULT_H
