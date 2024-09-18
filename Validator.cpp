#include "Validator.h"
#include <cctype>
#include "iostream"


bool Validator::has_enough_arguments(const std::vector<std::string>& arguments_list, int ExpectedArguments) {
    if (ExpectedArguments != arguments_list.size()){
        return false;
    }
    return true;
}

bool Validator::are_arguments_filled(const std::vector<std::string>& arguments_list) {
    for(const std::string& argument: arguments_list){
        if(argument.empty()){
            return false;
        }
    }
    return true;
}

bool Validator::is_column_capital(const std::string& column_string) {
    if (!is_all_uppercase(column_string)){
        return false;
    }
    return true;
}

bool Validator::does_column_exist(const std::string& column_string, int TableWidth) {
    int column_index = column_to_index(column_string);
    if (column_index > TableWidth - 1){
        return false;
    }
    return true;
}

bool Validator::column_type_validator(const std::string& column_string, const std::vector<std::string>& ValidTypes, const std::vector<std::string>& DataTypes) {
    int column_index = column_to_index(column_string);
    int types_validator = static_cast<int>(std::count(ValidTypes.begin(), ValidTypes.end(), DataTypes[column_index]));
    if (types_validator != 1){
        return false;
    }
    return true;
}

bool Validator::is_all_uppercase(const std::string &word) {
    for (char c: word) {
        if (!std::isupper(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

int Validator::column_to_index(const std::string &column) {
    int result = 0;
    for (char letter : column) {
        result = result * 26 + (letter - 'A' + 1);
    }
    return result - 1;
}

bool Validator::is_start_index_greater_than_0(int given_start_index) {
    if (given_start_index < 1){
        return false;
    }
    return true;
}

bool Validator::end_argument_greater_than_start_argument(int given_start_index, int given_end_index) {
    if (given_start_index > given_end_index){
        return false;
    }
    return true;
}

bool Validator::end_argument_not_out_of_range(int given_end_argument, int table_height) {
    if (given_end_argument > table_height){
        return false;
    }
    return true;
}

bool Validator::is_numeric(const std::string &text) {
    for (char c : text) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;

}

bool Validator::is_convertable_to_float(const std::string& text) {
    try {
        std::size_t pos;
        float f = std::stof(text, &pos);
        return pos == text.length();
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }
}

bool Validator::is_function(const std::string &text) {
    std::vector <std::string> ValidPrefixes{"SUM", "MIN", "MAX", "LEN", "LEFT", "RIGHT", "MEAN", "MOD", "DAY", "MONTH", "YEAR", "SORT"};
    int open_location = -1;
    int close_location = -1;
    for (int i = 0; i < text.size(); i++){
        if(text[i] == '('){
            open_location = i;
        }
        else if(text[i] == ')'){
            close_location = i;
        }
    }
    if (open_location == -1){
        std::cout << "Opening parenthesis was never found";
        return false;
    }
    if (close_location == -1){
        std::cout << "Closing parenthesis was never found";
        return false;
    }
    std::string found_prefix = Decomposer::prefix(text);
    int count;
    count = static_cast<int>(std::count(ValidPrefixes.begin(), ValidPrefixes.end(), found_prefix));
    if (count != 1){
        std::cout << "Invalid Prefix";
        return false;
    }
    return true;
}
