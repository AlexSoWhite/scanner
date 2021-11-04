//
// Created by alex on 04.11.2021.
//

#include <filesystem>
#include <iostream>
#include <vector>
#include "../include/Parser.h"

Parser::Parser() {
    this->fileNames = std::vector<std::string>();
}

Parser & Parser::parse(const std::string & directoryName) {
    for (const auto &entry: std::filesystem::directory_iterator(directoryName)) {
        this->fileNames.push_back(entry.path());
    }
    return *this;
}

std::vector<std::string> Parser::getFileNames() {
    return this->fileNames;
}

void Parser::printFileNames() {
    for (const auto & v: this->fileNames) {
        std::cout<<v<<std::endl;
    }
}