//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_ANALYSISRESULT_H
#define SCAN_UTIL_ANALYSISRESULT_H

// класс, объект которого хранит в себе результаты анализа, в том числе время
class AnalysisResult {
    unsigned long processedFiles;
    int jsDetects;
    int cmdDetects;
    int exeDetects;
    int errors;
    float startTime;
    float endTime;
public:
    AnalysisResult();
    void print() const;

    void setProcessedFiles(unsigned long filesAmount) { this->processedFiles = filesAmount; };

    void increaseJsDetects() { ++this->jsDetects; };

    void increaseCmdDetects() { ++this->cmdDetects; };

    void increaseExeDetects() { ++this->exeDetects; };

    void increaseErrors() { ++this->errors; };

    void setStartTime(float time) { this->startTime = time; };

    void setEndTime(float time) { this->endTime = time; };
};

#endif //SCAN_UTIL_ANALYSISRESULT_H
