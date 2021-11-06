//
// Created by alex on 04.11.2021.
//

#include <string>
#include <regex>
#include <map>
#include "../include/Dispatcher.h"
#include "../include/Scanner.h"

Dispatcher::Dispatcher() {
    // инициализируем типы файлов
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

void Dispatcher::start(const std::string &fileName, AnalysisResult &ar) {

    // проходим по типам файлов в поисках совпадения с текущим файлом
    for (const FileType & fType : fileTypes) {

        // с помощью регулярки проверяем расширение файла
        if (std::regex_search(fileName, fType.getFileTypeRegex())) {

            // запускаем сканнер и пишем результат сканирования в rt
            Scanner::Result rt = Scanner::scan(fileName, fType.getSuspiciousStrings());

            if (rt == Scanner::Result::ERROR) {
                ar.increaseErrors();
            }

            else if (rt == Scanner::Result::DETECTED) {
                switch (fType.getFileType()) {
                    case JS:
                        ar.increaseJsDetects();
                        break;
                    case CMD:
                    case BAT:
                        ar.increaseCmdDetects();
                        break;
                    case EXE:
                    case DLL:
                        ar.increaseExeDetects();
                        break;
                }
            }
            break;
        }
    }
}
