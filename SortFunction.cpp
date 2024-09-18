#include "SortFunction.h"


std::variant <Date, int, float, std::string> SortFunction::call(std::vector <Row>& table_data, const std::vector <std::string>& table_datatypes) {
    std::variant <Date, int, float, std::string> output = "";
    int height = static_cast<int>(table_data.size());
    int width = table_data[0].get_size();
    std::vector <std::string> arguments = Decomposer::arguments(Text);
    // is_valid
    if(!Validator::has_enough_arguments(arguments, ExpectedArguments)){
        std::cout << "Wrong amount of arguments used in SORT function";
        return output;
    }
    int column_index = Decomposer::column_to_int(arguments[0]);
    if(!Validator::are_arguments_filled(arguments)){
        std::cout << "Arguments cannot be empty!";
        return output;
    }
    std::string column = arguments[0];
    if(!Validator::is_column_capital(column)){
        std::cout << "First argument has to consist only of capital letters";
        return output;
    }
    if(!Validator::does_column_exist(column, width)){
        std::cout << "Given column does not exist in table";
        return output;
    }
    if(!Validator::column_type_validator(column, Datatypes, table_datatypes)){
        std::cout << "Function was called for column with wrong type of data";
        return output;
    }
    std::vector <std::variant<Date, int, float, std::string>> sorted_values;
    for (int index = 0; index < height; index++){
        sorted_values.push_back(table_data[index].get(column_index));
    }
    std::sort(sorted_values.begin(), sorted_values.end());
    std::vector <Row> new_table_data;
    std::vector <bool> already_added;
    for (int i = 0; i < table_data.size(); i++){
        already_added.emplace_back(false);
    }
    for (const auto & sorted_value : sorted_values){
        for (int index = 0; index < height; index++){
            if((table_data[index].get(column_index) == sorted_value) && (!already_added[index])){
                new_table_data.push_back(table_data[index]);
                already_added[index] = true;
            }
        }
    }
    table_data = new_table_data;
    return output;
}
