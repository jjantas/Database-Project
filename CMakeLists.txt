cmake_minimum_required(VERSION 3.28)
project(2024l_proi_204_projekt_baza_danych_vol2)

set(CMAKE_CXX_STANDARD 20)

add_executable(main
        main.cpp
        Date.cpp
        Database.cpp
        Database.cpp
        Row.cpp
        Row.cpp
        Function.cpp
        SumFunction.cpp
        Decomposer.cpp
        DataLoader.cpp
        Validator.cpp
        MinFunction.cpp
        MaxFunction.cpp
        LenFunction.cpp
        LeftFunction.cpp
        RightFunction.cpp
        MeanFunction.cpp
        ModFunction.cpp
        DayFunction.cpp
        MonthFunction.cpp
        YearFunction.cpp
        SortFunction.cpp
)

include(FetchContent)
FetchContent_Declare(
        testy
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG
        release-1.11.0
)
FetchContent_MakeAvailable(testy)

target_link_libraries(main PRIVATE gtest_main)
enable_testing()

add_executable(
        database_tests
        Tests.cpp
        Date.cpp
        Row.cpp
        Database.cpp
        DataLoader.cpp
        DayFunction.cpp
        Decomposer.cpp
        Function.cpp
        LeftFunction.cpp
        LenFunction.cpp
        MaxFunction.cpp
        MeanFunction.cpp
        MinFunction.cpp
        ModFunction.cpp
        MonthFunction.cpp
        RightFunction.cpp
        SortFunction.cpp
        SumFunction.cpp
        Validator.cpp
        YearFunction.cpp
)

target_link_libraries(
        database_tests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(database_tests)

