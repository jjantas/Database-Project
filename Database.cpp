#include "Database.h"

void Database::load(const std::string& path) {
    Datatypes = DataLoader::load_datatypes(path);
    Data = DataLoader::load_data(path, Datatypes);
    Width = static_cast<int>(Datatypes.size());
    ColumnWidths = DataLoader::load_column_widths(path);
    for(int i = 0; i < Datatypes.size(); i++){
        Headers.push_back(int_to_column(i));
    }
}

std::string Database::int_to_column(int column_index) {
    int incremented_number = column_index + 1;
    std::string result;
    while (incremented_number > 0) {
        incremented_number--;
        char letter;
        letter = char('A' + (incremented_number % 26));
        result += letter;
        incremented_number /= 26;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::ostream& operator<<(std::ostream& os, const std::variant<Date, int, float, std::string>& v) {
    std::visit([&os](auto&& arg) {
        os << arg;
    }, v);
    return os;
}

void Database::print() {
    std::cout << "\t |";
    int spaces_index = 0;
    for (const std::string & header : Headers){
        std::string space;
        for(int i = 0; i < ColumnWidths[spaces_index]; i++){
            space += " ";
        }
        std::cout << header << space;
        if (spaces_index < Headers.size() - 1){
            std::cout << "\t |";
        }
        spaces_index++;
    }
    std::cout << "\n";
    int index = 1;
    for(const Row & row : Data){
        std::string space;
        std::cout << index << "\t | ";
        std::vector <int> sizes = row.get_value_sizes();
        int row_index = 0;
        for (const std::variant<Date, int, float, std::string>& printed_element: row.get_data()){
            std::cout << printed_element;
            if (row_index < Width - 1){
                for (int j = 0; j < ColumnWidths[row_index] - sizes[row_index]; j++){
                    space += " ";
                }
                std::cout << space;
                space = "";
                std::cout <<  "\t | ";
            }
            row_index++;
        }
        std::cout << "\n";
        index++;
    }
}

void Database::launch() {
    std::string task;
    bool quit = false;
    while (!quit){
        std::cout << ">";
        std::cin >> task;
        if (task == "QUIT") {
            quit = true;
        }
        else if(task == "PRINT"){
            print();
        }
        else if(Validator::is_function(task)){
            call(task);
        }
        std::cout << "\n";
    }
}

void Database::call(const std::string& text) {
    std::string prefix = Decomposer::prefix(text);
    std::variant <Date, int, float, std::string> output;
    if (prefix == "SUM"){
        SumFunction sum(text);
        output = sum.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "MIN")
    {
        MinFunction min(text);
        output = min.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "MAX")
    {
        MaxFunction max(text);
        output = max.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "LEN")
    {
        LenFunction len(text);
        output = len.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "LEFT")
    {
        LeftFunction left(text);
        output = left.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "RIGHT")
    {
        RightFunction right(text);
        output = right.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "MEAN")
    {
        MeanFunction mean(text);
        output = mean.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "MOD")
    {
        ModFunction mod(text);
        output = mod.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "DAY")
    {
        DayFunction day(text);
        output = day.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "MONTH")
    {
        MonthFunction month(text);
        output = month.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "YEAR")
    {
        YearFunction year(text);
        output = year.call(Data, Datatypes);
        std::cout << output;
    }
    if (prefix == "SORT")
    {
        SortFunction sort(text);
        output = sort.call(Data, Datatypes);
        std::cout << output;
    }
}

