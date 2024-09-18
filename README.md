# Database Operations Documentation

This documentation provides an overview of the database operations project, which includes various functions for manipulating and analyzing data stored in a database.

## Introduction

The database operations project aims to provide a set of functions that allow users to perform common operations on a database, such as calculating aggregates, extracting substrings, and extracting date components. These functions are designed to be flexible and easy to use, allowing users to perform complex data manipulations with minimal effort.

## Functionality

The project consists of several key components:

1. **Database Class**: The `Database` class serves as the main interface for interacting with the database. It provides methods for loading data from a file, printing the contents of the database, and launching an interactive console for executing database operations.

2. **Function Classes**: There are several function classes, each implementing a specific database operation:
    - `SumFunction`: Calculates the sum of numeric values within a column across a given range of rows.
    - `MinFunction`: Finds the lowest value within a column across a given range of rows.
    - `MaxFunction`: Finds the biggest value within a column across a given range of rows.
    - `LenFunction`: Calculates string lengths within a specified column at a given row.
    - `LeftFunction`: Extracts a specified number of characters from the left side of a string.
    - `RightFunction`: Extracts a specified number of characters from the right side of a string.
    - `MeanFunction`: Computes the average numeric value in a column within a specified row range.
    - `ModFunction`: Calculates the modulo of numeric values in a column within a specified row range.
    - `DayFunction`: Extracts the day component from a date.
    - `MonthFunction`: Extracts the month component from a date.
    - `YearFunction`: Extracts the year component from a date.

   Each function class implements a `call()` method, which performs the specific database operation on the provided data.

3. **Validator Class**: The `Validator` class provides methods for validating arguments passed to the function classes. It ensures that the arguments are of the correct type and format before executing the database operation.

4. **Decomposer Class**: The `Decomposer` class provides methods for decomposing text into its components. It is used by the function classes to parse arguments passed to them.

## Usage

To use the database operations project, follow these steps:

1. Instantiate a `Database` object.
2. Load data into the database using the `load()` method.
3. Use the `launch()` method to start an interactive console.
4. Enter commands to perform various database operations, such as calculating aggregates or extracting substrings.

Here's an example of how to use the project:

```cpp
#include "Database.h"

int main() {
    Database db;
    db.load("data.csv");
    db.launch();
    return 0;
}
```

### Console Usage Examples:

#### MIN Function:
- **Command:** `MIN(B, 1, 5)`
    - **Description:** Retrieves the minimum value from column B within the range of rows 1 to 5.

#### LEN Function:
- **Command:** `LEN(B, 3)`
    - **Description:** Calculates the length of the string in column B at row 3.

#### MEAN Function:
- **Command:** `MEAN(C, 1, 10)`
    - **Description:** Computes the average value of numeric data in column C within rows 1 to 10.

