#include "MaxFunction.h"


std::variant <Date, int, float, std::string> MaxFunction::call(std::vector <Row>& table_data, const std::vector <std::string>& table_datatypes)
{
    std::variant <Date, int, float, std::string> output = "";
    int height = static_cast<int>(table_data.size());
    int width = table_data[0].get_size();
    std::vector <std::string> arguments = Decomposer::arguments(Text);
    // is_valid
    if(!Validator::has_enough_arguments(arguments, ExpectedArguments)){
        std::cout << "Wrong amount of arguments used in MAX function";
        return output;
    }
    int column_index = Decomposer::column_to_int(arguments[0]);
    int start_index= std::stoi(arguments[1]);
    int end_index= std::stoi(arguments[2]);
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
    if (!Validator::is_numeric(arguments[1])){
        std::cout << "Second argument must be numeric";
        return output;
    }
    if (!Validator::is_numeric(arguments[2])){
        std::cout << "Third argument must be numeric";
        return output;
    }
    if (!Validator::end_argument_greater_than_start_argument(start_index, end_index)){
        std::cout << "Second argument cannot be greater than third argument";
        return output;
    }
    if (!Validator::is_start_index_greater_than_0(start_index)){
        std::cout << "Second argument cannot be smaller than 1";
        return output;
    }
    if (!Validator::end_argument_not_out_of_range(end_index, height)){
        std::cout << "Third argument cannot be greater than height of table";
        return output;
    }
    Row row = table_data[start_index - 1];
    output = row.get(column_index);
    for (int i = start_index; i < end_index ; i++){
        row = table_data[i];
        if (row.get(column_index) > output){
            output = row.get(column_index);
        }
    }
    return output;
}
