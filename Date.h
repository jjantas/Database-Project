#include <stdexcept>
#include <iostream>
#pragma once


class Date {
private:
    int Day;
    int Month;
    int Year;
    bool LeapYear;
public:
    Date();
    Date(int day, int month, int year);
    static bool is_leap(int year);
    static int days_in_month(int month, bool leapYear);
    [[nodiscard]] int get_day() const;
    [[nodiscard]] int get_month() const;
    [[nodiscard]] int get_year() const;

    bool operator<(const Date &another_date) const;
    bool operator>(const Date &another_date) const;
    bool operator>=(const Date &another_date) const;
    bool operator<=(const Date &another_date) const;
    friend bool operator==(const Date& date1, const Date& date2);

};

std::ostream& operator <<(std::ostream& os, Date date);