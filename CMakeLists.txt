cmake_minimum_required(VERSION 3.16)
project(scan_util)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-pthread -Wall")
add_executable(scan_util
                main.cpp
                src/Parser.cpp
                include/Parser.h
                src/Scanner.cpp
                include/Scanner.h
                src/Dispatcher.cpp
                include/Dispatcher.h
                src/FileType.cpp
                include/FileType.h
                src/AnalysisResult.cpp
                include/AnalysisResult.h
        )