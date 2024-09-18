#include "gtest/gtest.h"
#include "Date.h"
#include "gtest/gtest.h"
#include "DataLoader.h"
#include "Row.h"
#include "Date.h"
#include "SumFunction.h"
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
#include <fstream>


TEST(DataLoaderTest, LoadDataTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    ASSERT_EQ(datatypes.size(), 4);
    EXPECT_EQ(datatypes[0], "date");
    EXPECT_EQ(datatypes[1], "int");
    EXPECT_EQ(datatypes[2], "float");
    EXPECT_EQ(datatypes[3], "str");

    ASSERT_EQ(data.size(), 3);
    EXPECT_EQ(data[0].get_size(), 4);
    EXPECT_EQ(data[1].get_size(), 4);
    EXPECT_EQ(data[2].get_size(), 4);
}


TEST(RowAndDateTest, RowAndDateFunctionalityTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    Row row = data[0];
    EXPECT_EQ(std::get<Date>(row.get(0)).get_day(), 1);
    EXPECT_EQ(std::get<Date>(row.get(0)).get_month(), 6);
    EXPECT_EQ(std::get<Date>(row.get(0)).get_year(), 2024);

    EXPECT_EQ(std::get<int>(row.get(1)), 123);
    EXPECT_FLOAT_EQ(std::get<float>(row.get(2)), 45.67);
    EXPECT_EQ(std::get<std::string>(row.get(3)), "test1");
}


TEST(FunctionalityTest, SumFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    SumFunction sumFunc("SUM(B,1,3)");
    auto sumResult = sumFunc.call(data, datatypes);
    EXPECT_FLOAT_EQ(std::get<float>(sumResult), 1368.0);
}


TEST(FunctionalityTest, MinFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    MinFunction minFunc("MIN(B,1,3)");
    auto minResult = minFunc.call(data, datatypes);
    EXPECT_EQ(std::get<int>(minResult), 123);
}


TEST(FunctionalityTest, MaxFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    MaxFunction maxFunc("MAX(B,1,3)");
    auto maxResult = maxFunc.call(data, datatypes);
    EXPECT_EQ(std::get<int>(maxResult), 789);
}


TEST(FunctionalityTest, LenFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    LenFunction lenFunc("LEN(D,1)");
    auto lenResult = lenFunc.call(data, datatypes);
    EXPECT_EQ(std::get<int>(lenResult), 5);
}


TEST(FunctionalityTest, LeftFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    LeftFunction leftFunc("LEFT(D,1,4)");
    auto leftResult = leftFunc.call(data, datatypes);
    EXPECT_EQ(std::get<std::string>(leftResult), "test");
}


TEST(FunctionalityTest, RightFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    RightFunction rightFunc("RIGHT(D,1,3)");
    auto rightResult = rightFunc.call(data, datatypes);
    EXPECT_EQ(std::get<std::string>(rightResult), "st1");
}


TEST(FunctionalityTest, MeanFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    MeanFunction meanFunc("MEAN(B,1,3)");
    auto meanResult = meanFunc.call(data, datatypes);
    EXPECT_FLOAT_EQ(std::get<float>(meanResult), (123 + 456 + 789) / 3.0);
}


TEST(FunctionalityTest, ModFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    ModFunction modFunc("MOD(B,1,2)");
    auto modResult = modFunc.call(data, datatypes);
    EXPECT_FLOAT_EQ(std::get<float>(modResult), 1.0);
}


TEST(FunctionalityTest, DayFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    DayFunction dayFunc("DAY(A,1)");
    auto dayResult = dayFunc.call(data, datatypes);
    EXPECT_EQ(std::get<int>(dayResult), 1);
}


TEST(FunctionalityTest, MonthFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    MonthFunction monthFunc("MONTH(A,1)");
    auto monthResult = monthFunc.call(data, datatypes);
    EXPECT_EQ(std::get<int>(monthResult), 6);
}


TEST(FunctionalityTest, YearFunctionTest) {
    std::vector<std::string> datatypes = DataLoader::load_datatypes("data_example.txt");
    std::vector<Row> data = DataLoader::load_data("data_example.txt", datatypes);

    YearFunction yearFunc("YEAR(A,1)");
    auto yearResult = yearFunc.call(data, datatypes);
    EXPECT_EQ(std::get<int>(yearResult), 2024);
}

TEST(DateTest, ConstructorAndGetters) {
    Date date(10, 5, 2024);
    EXPECT_EQ(date.get_day(), 10);
    EXPECT_EQ(date.get_month(), 5);
    EXPECT_EQ(date.get_year(), 2024);
}

TEST(DateTest, LeapYear) {
    EXPECT_TRUE(Date::is_leap(2024));
    EXPECT_FALSE(Date::is_leap(2021));
    EXPECT_FALSE(Date::is_leap(1900)); // Not a leap year due to being divisible by 100 but not 400
    EXPECT_TRUE(Date::is_leap(2000));  // Leap year due to being divisible by 400
}

TEST(DateTest, DaysInMonth) {
    EXPECT_EQ(Date::days_in_month(2, false), 28); // February, non-leap year
    EXPECT_EQ(Date::days_in_month(2, true), 29);  // February, leap year
    EXPECT_EQ(Date::days_in_month(4, false), 30); // April
    EXPECT_EQ(Date::days_in_month(7, false), 31); // July
}

TEST(DateTest, ComparisonOperators) {
    Date date1(10, 5, 2024);
    Date date2(12, 5, 2024);
    Date date3(10, 6, 2024);
    Date date4(10, 5, 2023);

    EXPECT_TRUE(date1 == date1);
    EXPECT_TRUE(date1 < date2);
    EXPECT_TRUE(date1 < date3);
    EXPECT_TRUE(date1 > date4);
    EXPECT_TRUE(date2 > date1);
}

TEST(DecomposerTest, Prefix_ValidCase) {
    std::string text = "SUM(A1:A10)";
    EXPECT_EQ(Decomposer::prefix(text), "SUM");
}

TEST(DecomposerTest, Prefix_EmptyText) {
    std::string text = "";
    EXPECT_EQ(Decomposer::prefix(text), "");
}

TEST(DecomposerTest, Arguments_ValidCase) {
    std::string text = "MAX(A,10)";
    EXPECT_EQ(Decomposer::arguments(text)[0], "A");
    EXPECT_EQ(Decomposer::arguments(text)[1], "10");
}

TEST(DecomposerTest, Arguments_EmptyText) {
    std::string text = "";
    EXPECT_TRUE(Decomposer::arguments(text).empty());
}


TEST(DecomposerTest, ColumnToInt_ValidCase) {
    std::string column = "AB";
    EXPECT_EQ(Decomposer::column_to_int(column), 27);
}


TEST(DecomposerTest, ColumnToInt_SingleLetterColumn) {
    std::string column = "A";
    EXPECT_EQ(Decomposer::column_to_int(column), 0);
}

TEST(RowTest, DefaultConstructor) {
    Row row;
    EXPECT_TRUE(row.get_data().empty());
    EXPECT_EQ(row.get_size(), 0);
}

TEST(RowTest, LoadData) {
    std::vector<std::string> data = {"1.6.2024", "123", "45.67", "test"};
    std::vector<std::string> data_types = {"date", "int", "float", "str"};
    Row row;
    row.load(data, data_types);

    ASSERT_EQ(row.get_size(), 4);

    EXPECT_EQ(std::get<Date>(row.get(0)).get_day(), 1);
    EXPECT_EQ(std::get<Date>(row.get(0)).get_month(), 6);
    EXPECT_EQ(std::get<Date>(row.get(0)).get_year(), 2024);

    EXPECT_EQ(std::get<int>(row.get(1)), 123);
    EXPECT_FLOAT_EQ(std::get<float>(row.get(2)), 45.67);
    EXPECT_EQ(std::get<std::string>(row.get(3)), "test");
}

TEST(RowTest, GetValueSizes) {
    std::vector<std::string> data = {"1.6.2024", "123", "45.67", "test"};
    std::vector<std::string> data_types = {"date", "int", "float", "str"};
    Row row;
    row.load(data, data_types);

    std::vector<int> value_sizes = row.get_value_sizes();
    ASSERT_EQ(value_sizes.size(), 4);
    EXPECT_EQ(value_sizes[0], data[0].size());
    EXPECT_EQ(value_sizes[1], data[1].size());
    EXPECT_EQ(value_sizes[2], data[2].size());
    EXPECT_EQ(value_sizes[3], data[3].size());
}

TEST(ValidatorTest, HasEnoughArguments) {
    std::vector<std::string> args1 = {"arg1", "arg2", "arg3"};
    std::vector<std::string> args2 = {"arg1", "arg2"};
    EXPECT_TRUE(Validator::has_enough_arguments(args1, 3));
    EXPECT_FALSE(Validator::has_enough_arguments(args2, 3));
}


TEST(ValidatorTest, AreArgumentsFilled) {
    std::vector<std::string> filledArgs = {"arg1", "arg2", "arg3"};
    std::vector<std::string> emptyArgs = {"", "arg2", "arg3"};
    EXPECT_TRUE(Validator::are_arguments_filled(filledArgs));
    EXPECT_FALSE(Validator::are_arguments_filled(emptyArgs));
}

TEST(ValidatorTest, IsColumnCapital) {
    std::string capitalColumn = "COLUMN";
    std::string nonCapitalColumn = "column";
    EXPECT_TRUE(Validator::is_column_capital(capitalColumn));
    EXPECT_FALSE(Validator::is_column_capital(nonCapitalColumn));
}

TEST(ValidatorTest, DoesColumnExist_ValidCase) {
    std::string column = "C";
    int tableWidth = 3;
    EXPECT_TRUE(Validator::does_column_exist(column, tableWidth));
}

TEST(ValidatorTest, DoesColumnExist_InvalidCase) {
    std::string column = "D";
    int tableWidth = 3;
    EXPECT_FALSE(Validator::does_column_exist(column, tableWidth));
}

TEST(ValidatorTest, ColumnTypeValidator_ValidCase) {
    std::string column = "A";
    std::vector<std::string> validTypes = {"int", "float", "str"};
    std::vector<std::string> dataTypes = {"int", "float", "str"};
    EXPECT_TRUE(Validator::column_type_validator(column, validTypes, dataTypes));
}

TEST(ValidatorTest, ColumnTypeValidator_InvalidCase) {
    std::string column = "B";
    std::vector<std::string> validTypes = {"int", "float", "str"};
    std::vector<std::string> dataTypes = {"int", "str", "str"};
    EXPECT_TRUE(Validator::column_type_validator(column, validTypes, dataTypes));
}

TEST(ValidatorTest, IsAllUppercase_ValidCase) {
    std::string word = "HELLO";
    EXPECT_TRUE(Validator::is_all_uppercase(word));
}

TEST(ValidatorTest, IsAllUppercase_InvalidCase) {
    std::string word = "Hello";
    EXPECT_FALSE(Validator::is_all_uppercase(word));
}