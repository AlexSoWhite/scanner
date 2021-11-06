#include <iostream>
#include <chrono>
#include <thread>
#include "include/Parser.h"
#include "include/Dispatcher.h"
#include "include/AnalysisResult.h"

void thread_proc(Dispatcher& dispatcher, Parser& parser, AnalysisResult& ar, unsigned int thread_id) {
    // передача имён файлов в диспетчер, который внутри себя будет вызывать сканнеры с подходящими аргументами
    for (uint i = thread_id; i < parser.getFileNames().size(); i += std::thread::hardware_concurrency()) {
        dispatcher.start(parser.getFileNames().at(i), ar);
    }
}

int main(int argc, const char *argv[]) {

    auto begin = std::chrono::steady_clock::now();

    if (argc != 2) {
        std::cout<<"usage: ./scan_util [directory-name]"<<std::endl;
        return 0;
    }

    // сюда мы будем писать результаты анализа
    AnalysisResult ar = AnalysisResult();

    // создаем парсер для получения имен файлов
    Parser parser = Parser();

    // получение списка имен файлов в указанной директории
    parser.parse(argv[1]);

    // инициализация диспетчера
    Dispatcher& dispatcher = Dispatcher::init();

    // создание потоков для параллельного сканирования
    unsigned int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    threads.reserve(numThreads);
    for (unsigned int i = 0; i < numThreads; i++) {
        // создаем потоки, каждый из которых будет обрабатывать файлы начиная с индекса i с шагом hardware_concurrency
        std::thread thr (thread_proc, std::ref(dispatcher), std::ref(parser), std::ref(ar), i);
        threads.emplace_back(std::move(thr));
    }

    for (std::thread & t: threads) {
        t.join();
    }

    auto end = std::chrono::steady_clock::now();
    double execTime = std::chrono::duration<double>(end-begin).count();

    // упаковка оставшихся данных о результате в ar и вывод в консоль
    ar.setProcessedFiles(parser.getFileNames().size());
    ar.setTime(execTime);
    ar.print();
    return 0;
}
