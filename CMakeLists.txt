cmake_minimum_required(VERSION 3.20)
project(scan_util)

set(CMAKE_CXX_STANDARD 17)

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
                src/FileTypes.cpp
                include/FileTypes.h
                include/Pattern.h
                src/AnalysisResult.cpp
                include/AnalysisResult.h
                include/ResultTypes.h
            )