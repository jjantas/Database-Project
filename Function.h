#include <string>
#include <utility>
#include <vector>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <cmath>
#include "Row.h"
#include "algorithm"
#include "Validator.h"
#include "Decomposer.h"
#pragma once


class Function {
public:
    std::string Text;
    std::vector <std::string> Datatypes;
    int ExpectedArguments;
    Function(std::string text, std::vector <std::string> datatypes, int args):
    Text(std::move(text)), Datatypes(std::move(datatypes)), ExpectedArguments(args){};
    virtual bool is_valid();
    virtual std::variant <Date, int, float, std::string> call(std::vector <Row>& data, const std::vector <std::string>& table_datatypes);
};
