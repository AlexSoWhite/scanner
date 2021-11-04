#include <iostream>
#include "include/Parser.h"
#include "include/Dispatcher.h"
#include "include/AnalysisResult.h"
int main(int argc, const char *argv[]) {

    clock_t begin = clock();

    // сюда мы будем писать результаты анализа
    AnalysisResult ar = AnalysisResult();

    if (argc!=2) {
        std::cout<<"usage: scan_util [directory name]"<<std::endl;
        return 0;
    }

    Parser parser = Parser();
    Dispatcher dispatcher = Dispatcher();

    // получение списка имен файлов в указанной директории
    parser.parse(argv[1]);

    // передача имён файлов в диспетчер, который внутри себя будет вызывать сканнеры с подходящими аргументами
    for (const std::string& fName : parser.getFileNames()) {
        dispatcher.start(fName, ar);
    }

    clock_t end = clock();

    ar.setProcessedFiles(parser.getFileNames().size());
    ar.setStartTime(begin);
    ar.setEndTime(end);
    ar.print();
    return 0;
}
