#include <vector>
#include <string>
#include <fstream>
#include "iostream"
#include "algorithm"
#pragma once


class Decomposer {
public:
    Decomposer()= default;
    static std::string prefix(const std::string& text);
    static std::vector <std::string> arguments(const std::string& text);
    static std::vector<std::string> splitter(const std::string &row_from_text);
    static int column_to_int(const std::string& column);
};
