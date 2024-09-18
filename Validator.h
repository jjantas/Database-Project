#include "string"
#include "vector"
#include "algorithm"
#include "Decomposer.h"


class Validator{
public:
    Validator() = default;
    static bool has_enough_arguments(const std::vector<std::string>& arguments_list, int ExpectedArguments) ;
    static bool are_arguments_filled(const std::vector<std::string>& arguments_list) ;
    static bool is_column_capital(const std::string& column_string) ;
    static bool does_column_exist(const std::string& column_string, int TableWidth) ;
    static bool column_type_validator(const std::string& column_string, const std::vector<std::string>& ValidTypes, const std::vector<std::string>& DataTypes) ;
    static bool is_all_uppercase(const std::string& word) ;
    static bool is_start_index_greater_than_0(int given_start_index);
    static bool end_argument_greater_than_start_argument(int given_start_index, int given_end_index);
    static bool end_argument_not_out_of_range(int given_end_argument, int table_height);
    static bool is_numeric(const std::string &text);
    static bool is_function(const std::string &text);
    static int column_to_index(const std::string& column);
    static bool is_convertable_to_float(const std::string& text);
};
