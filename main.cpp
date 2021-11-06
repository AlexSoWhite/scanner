#include <iostream>
#include "include/Parser.h"
#include "include/Dispatcher.h"
#include "include/AnalysisResult.h"
#include <omp.h>

int main(int argc, const char *argv[]) {

    if (argc != 2) {
        std::cout<<"usage: ./scan_util [directory-name]"<<std::endl;
        return 0;
    }

    // сюда мы будем писать результаты анализа
    AnalysisResult ar = AnalysisResult();

    float begin = omp_get_wtime();

    Parser parser = Parser();

    // получение списка имен файлов в указанной директории
    parser.parse(argv[1]);

    Dispatcher& dispatcher = Dispatcher::init();
    // передача имён файлов в диспетчер, который внутри себя будет вызывать сканнеры с подходящими аргументами
    #pragma omp parallel shared(parser, ar, dispatcher) default(none)
    #pragma omp for schedule(dynamic)
    for (const std::string& fName : parser.getFileNames()) {
        dispatcher.start(fName, ar);
    }

    float end = omp_get_wtime();

    // упаковка оставшихся данных о результате в ar и вывод в консоль
    ar.setProcessedFiles(parser.getFileNames().size());
    ar.setStartTime(begin);
    ar.setEndTime(end);
    ar.print();
    return 0;
}
