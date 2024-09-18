#include <vector>
#include <string>
#include "DataLoader.h"
#include "SumFunction.h"
#include "Decomposer.h"
#include "MinFunction.h"
#include "MaxFunction.h"
#include "LenFunction.h"
#include "LeftFunction.h"
#include "RightFunction.h"
#include "MeanFunction.h"
#include "ModFunction.h"
#include "DayFunction.h"
#include "MonthFunction.h"
#include "YearFunction.h"
#include "SortFunction.h"


class Database {
private:
    std::vector<std::string> Datatypes;
    std::vector<std::string> Headers;
    std::vector<Row> Data;
    std::vector<int> ColumnWidths;
    Decomposer decomposer;
    int Width{};
    static std::string int_to_column(int column_index);

public:
    Database()=default;
    void load(const std::string&);
    void print();
    void launch();
    void call(const std::string& text);
};
