//
// Created by alex on 04.11.2021.
//

#ifndef SCAN_UTIL_PATTERN_H
#define SCAN_UTIL_PATTERN_H


class Pattern {
public:
    std::string source;
    std::regex reg;
    Pattern() = default;
    explicit Pattern(const std::string& src) {
        this->source = src;
        this->reg = std::regex(src);
    }
};


#endif //SCAN_UTIL_PATTERN_H
