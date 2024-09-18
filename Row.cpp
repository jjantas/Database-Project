#include "Row.h"


Row::Row() {
    std::vector <std::variant<Date, int, float, std::string>> data;
    Data = data;
    std::vector <int> columnLengths;
    ColumnLengths = columnLengths;
    std::vector <std::string> dataTypes;
    DataTypes = dataTypes;
}

void Row::load(const std::vector<std::string>& data, std::vector<std::string> data_types) {
    for (int index = 0; index < data_types.size(); index++) {
        ValueSizes.emplace_back(data[index].size());
        if (data_types[index] == "date"){
            std::vector<std::string> date_attributes;
            std::string w;
            for (char x: data[index]) {
                if (x == '.') {
                    date_attributes.push_back(w);
                    w = "";
                } else {
                    w += x;
                }
            }
            date_attributes.push_back(w);
            int day = std::stoi(date_attributes[0]);
            int month = std::stoi(date_attributes[1]);
            int year = std::stoi(date_attributes[2]);
            Date to_be_turned_into_variant(day, month, year);
            std::variant<Date, int, float, std::string> data_piece = to_be_turned_into_variant;
            Data.emplace_back(data_piece);
        }
        else if (data_types[index] == "int"){
            std::variant<Date, int, float, std::string> data_piece = std::stoi(data[index]);
            Data.emplace_back(data_piece);
        }
        else if (data_types[index] == "float"){
            std::variant<Date, int, float, std::string> data_piece = std::stof(data[index]);
            Data.emplace_back(data_piece);
        }
        else if (data_types[index] == "str"){
            std::variant<Date, int, float, std::string> data_piece = data[index];
            Data.emplace_back(data_piece);
        }
        else{
            std::cout << "Invalid data types in given txt file";
        }
        ColumnLengths.emplace_back(data[index].length());
    }
}

std::variant<Date, int, float, std::string> Row::get(int index) {
    return Data[index];
}

const std::vector<std::variant<Date, int, float, std::string>>& Row::get_data() const{
    return Data;
}

std::vector<int> Row::get_value_sizes() const{
    return ValueSizes;
}

int Row::get_size() {
    return static_cast<int>(Data.size());
}
