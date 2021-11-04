//
// Created by alex on 04.11.2021.
//

#include <string>
#include <regex>
#include <iostream>
#include "../include/Dispatcher.h"
#include "../include/Scanner.h"

Dispatcher::Dispatcher() {
    this->fileTypes = FileTypes();
}

void Dispatcher::start(const std::string &fileName, AnalysisResult &ar) {
    for (const FileType & fType : fileTypes.getFileTypes()) {
        if (std::regex_search(fileName, fType.getFileTypeRegex().reg)) {
            //std::cout << fileName << " is " << fType.getFileTypeString() << std::endl;
            Scanner scanner = Scanner();
            ResultTypes rt = scanner.scan(fileName, fType.getSuspiciousStrings());

            if (rt == ResultTypes::ERROR) {
                ar.increaseErrors();
            }

            else if (rt == ResultTypes::DETECTED) {
                switch (fType.getFileType()) {
                    case FileTypes::JS:
                        ar.increaseJsDetects();
                        break;
                    case FileTypes::CMD:
                        ar.increaseCmdDetects();
                        break;
                    case FileTypes::BAT:
                        ar.increaseCmdDetects();
                        break;
                    case FileTypes::EXE:
                        ar.increaseExeDetects();
                        break;
                    case FileTypes::DLL:
                        ar.increaseExeDetects();
                        break;
                }
            }
            break;
        }
    }
}