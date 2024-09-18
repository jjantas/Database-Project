#include "Date.h"
#include "vector"
#include "variant"
#pragma once


class Row{
private:
    std::vector <std::variant<Date, int, float, std::string>> Data;
    std::vector <int> ColumnLengths;
    std::vector <int> ValueSizes;
    std::vector <std::string> DataTypes;
public:
    Row();
    [[nodiscard]] const std::vector <std::variant<Date, int, float, std::string>>& get_data() const;
    [[nodiscard]] std::vector <int> get_value_sizes() const;
    void load(const std::vector<std::string>& data, std::vector <std::string> data_types);
    std::variant<Date, int, float, std::string> get(int index);
    int get_size();
};
