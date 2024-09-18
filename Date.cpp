#include "Date.h"
#include <stdexcept>

Date::Date(): Day(1), Month(1), Year(2000){
    Day = 1;
    Month = 1;
    Year = 2000;
    LeapYear = is_leap(Year);
}


Date::Date(int day, int month, int year) {
    LeapYear = is_leap(year);
    if (day > days_in_month(month, LeapYear)){
        throw std::invalid_argument("Invalid day argument ");
    }
    else{
        Day = day;
    }
    if ((month < 1) || (month > 12)){
        throw std::invalid_argument("Invalid month argument ");
    }
    else{
        Month = month;
    }
    Year = year;
}

bool Date::is_leap(int year) {
    if (year % 4 == 0){
        if ((year % 400 != 0) && (year % 100 == 0)){
            return false;
        }
        return true;
    }
    return false;
}

int Date::days_in_month(int month, bool leapYear) {
    if ((month == 4) || (month == 6) || (month == 9) ||
        (month == 11)) {
        return 30;
    } else if (month == 2) {
        if (leapYear) {
            return 29;
        } else {
            return 28;
        }
    } else {
        return 31;
    }
}

int Date::get_day() const {
    return Day;
}

int Date::get_month() const {
    return Month;
}

int Date::get_year() const {
    return Year;
}

std::ostream& operator <<(std::ostream& os, Date date)
{
    os << date.get_day() << "." << date.get_month() << "." << date.get_year();
    return os;
}

bool Date::operator <(const Date &another_date) const {
    if (another_date.get_year() != Year){
        return (another_date.get_year() > Year);
    }
    else if (another_date.get_month() != Month){
        return (another_date.get_month() > Month);
    }
    else{
        return (another_date.get_day() > Day);
    }
}

bool operator==(const Date& date1, const Date& date2){
    return date1.get_day() == date2.get_day() && date1.get_month() == date2.get_month() && date1.get_year() == date2.get_year();
}

bool Date::operator>(const Date &another_date) const {
    if (another_date.get_year() != Year){
        return (another_date.get_year() < Year);
    }
    else if (another_date.get_month() != Month){
        return (another_date.get_month() < Month);
    }
    else{
        return (another_date.get_day() < Day);
    }
}

bool Date::operator>=(const Date &another_date) const {
    return !(*this < another_date);
}

bool Date::operator<=(const Date &another_date) const {
    return !(another_date < *this);
}
