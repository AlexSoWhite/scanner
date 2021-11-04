#include <iostream>
#include "include/Parser.h"
#include "include/Dispatcher.h"
#include "include/AnalysisResult.h"
#include <omp.h>
int main(int argc, const char *argv[]) {

    clock_t bgn = clock();
    float begin = omp_get_wtime();
    // сюда мы будем писать результаты анализа
    AnalysisResult ar = AnalysisResult();

    if (argc != 2) {
        std::cout<<"usage: scan_util [directory name]"<<std::endl;
        return 0;
    }

    Parser parser = Parser();
    Dispatcher dispatcher = Dispatcher();

    // получение списка имен файлов в указанной директории
    parser.parse(argv[1]);

    // передача имён файлов в диспетчер, который внутри себя будет вызывать сканнеры с подходящими аргументами
    #pragma omp parallel shared(parser, ar, dispatcher) default(none)
    #pragma omp for schedule(dynamic)
    for (const std::string& fName : parser.getFileNames()) {
        dispatcher.start(fName, ar);
    }

    clock_t nd = clock();
    float end = omp_get_wtime();
    ar.setProcessedFiles(parser.getFileNames().size());
    ar.setStartTime(begin);
    ar.setEndTime(end);
    ar.print();
    std::cout << (nd - bgn)/CLOCKS_PER_SEC << std::endl;
    return 0;
}
