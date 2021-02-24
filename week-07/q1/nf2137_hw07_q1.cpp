#include <iostream>
#include <vector>
#include <cmath>
using std::vector, std::string, std::pair, std::make_pair;

vector<string> DAYS_OF_WEEK = {
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat",
    "Sun"
};

vector<pair<string, int>> MONTHS_OF_YEAR{
    make_pair("January", 31),
    make_pair("February", 28),
    make_pair("March", 31),
    make_pair("April", 30),
    make_pair("May", 31),
    make_pair("June", 30),
    make_pair("July", 31),
    make_pair("August", 31),
    make_pair("September", 30),
    make_pair("October", 31),
    make_pair("November", 30),
    make_pair("December", 31)
};

int printMonthCalendar(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalendar(int year, int startingDay);

int main() {
    printYearCalendar(2016, 5);
    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay) {
    for (int i = 0; i < DAYS_OF_WEEK.size(); ++i) {
        std::cout << DAYS_OF_WEEK[i] << "\t";
    }
    std::cout << std::endl;

    int weeks = static_cast<int>(ceil(static_cast<double>((numOfDays + startingDay)) / 7));
    int currentDay = 1;

    for (int week = 1; week <= weeks; ++week) {
        for (int day = 1; day <= 7; ++day) {
            if (
                    (week == 1 && day < startingDay) ||
                    (week == weeks && currentDay > numOfDays)
            ){
                std::cout << '\t';
            } else {
                std::cout << currentDay++ << '\t';
            }
        }
        std::cout << std::endl;
    }

    int nextMonthOffset = 7 - (weeks * 7 - numOfDays - startingDay);
    return nextMonthOffset;
}

bool isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 >= 1 || year % 100 == 0 && year % 400 == 0);
}

void printYearCalendar(int year, int startingDay) {
    bool leapYear = isLeapYear(year);

    int startDayOfMonth = startingDay;
    for (int month = 0; month < MONTHS_OF_YEAR.size(); ++month) {
        pair<string, int> currentMonth = MONTHS_OF_YEAR[month];
        std::cout << currentMonth.first << " " << year << std::endl;
        int numOfDays = leapYear && month == 1 ? currentMonth.second + 1 : currentMonth.second;
        startDayOfMonth = printMonthCalendar(numOfDays, startDayOfMonth);
        std::cout << std::endl;
    }
}