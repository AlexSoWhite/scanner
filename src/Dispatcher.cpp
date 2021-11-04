//
// Created by alex on 04.11.2021.
//

#include <string>
#include <regex>
#include <omp.h>
#include "../include/Dispatcher.h"
#include "../include/Scanner.h"

Dispatcher::Dispatcher() {
    // инициализируем типы файлов
    this->fileTypes = FileTypes();
}

void Dispatcher::start(const std::string &fileName, AnalysisResult &ar) {

    omp_lock_t lock;
    omp_init_lock(&lock);

    // проходим по типам файлов в поисках совпадения с текущим файлом
    for (const FileType & fType : fileTypes.getFileTypes()) {

        // с помощью регулярки проверяем расширение файла
        if (std::regex_search(fileName, fType.getFileTypeRegex().reg)) {

            // запускаем сканнер и пишем результат сканирования в rt
            ResultTypes rt = Scanner::scan(fileName, fType.getSuspiciousStrings());

            omp_set_lock(&lock);
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
            omp_unset_lock(&lock);
            break;
        }
    }
}
