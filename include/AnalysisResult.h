//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_ANALYSISRESULT_H
#define SCAN_UTIL_ANALYSISRESULT_H

// класс, объект которого хранит в себе результаты анализа, в том числе время
class AnalysisResult {
    unsigned long processedFiles;
    unsigned long jsDetects;
    unsigned long cmdDetects;
    unsigned long exeDetects;
    unsigned long errors;
    double time;
public:
    AnalysisResult(); // инициализация полей нулями
    void print() const;
    void setProcessedFiles(unsigned long filesAmount) { this->processedFiles = filesAmount; };
    void increaseJsDetects() { ++this->jsDetects; };
    void increaseCmdDetects() { ++this->cmdDetects; };
    void increaseExeDetects() { ++this->exeDetects; };
    void increaseErrors() { ++this->errors; };
    void setTime(double execTime) { this->time = execTime; };
};

#endif //SCAN_UTIL_ANALYSISRESULT_H
