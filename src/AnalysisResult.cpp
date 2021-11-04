//
// Created by alex on 04.11.2021.
//

#include <iostream>
#include "../include/AnalysisResult.h"

AnalysisResult::AnalysisResult() {
    this->processedFiles = 0;
    this->jsDetects = 0;
    this->cmdDetects = 0;
    this->exeDetects = 0;
    this->errors = 0;
    this->startTime = 0;
    this->endTime = 0;
}

void AnalysisResult::print() const {
    std::cout<<"====== Scan result ======"<<std::endl;
    std::cout<<"Processed files: "<<processedFiles<<std::endl;
    std::cout<<"JS detects: "<<jsDetects<<std::endl;
    std::cout<<"CMD detects: "<<cmdDetects<<std::endl;
    std::cout<<"EXE detects: "<<exeDetects<<std::endl;
    std::cout<<"Errors: "<<errors<<std::endl;
    std::cout<<"Execution time: "<<(endTime-startTime)/CLOCKS_PER_SEC<<std::endl;
    std::cout<<"========================="<<std::endl;
}

