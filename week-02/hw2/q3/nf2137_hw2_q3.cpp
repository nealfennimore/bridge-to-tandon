#include <iostream>

const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;

int main() {
    int daysJohn, hoursJohn, minutesJohn;
    int daysBill, hoursBill, minutesBill;

    std::cout << "Please enter the amount of days John has worked" << std::endl;
    std::cin >> daysJohn;
    std::cout << "Please enter the amount of hours John has worked" << std::endl;
    std::cin >> hoursJohn;
    std::cout << "Please enter the amount of minutes John has worked" << std::endl;
    std::cin >> minutesJohn;

    std::cout << "Please enter the amount of days Bill has worked" << std::endl;
    std::cin >> daysBill;
    std::cout << "Please enter the amount of hours Bill has worked" << std::endl;
    std::cin >> hoursBill;
    std::cout << "Please enter the amount of minutes Bill has worked" << std::endl;
    std::cin >> minutesBill;

    int minutes = minutesBill + minutesJohn;
    int hours = hoursBill + hoursJohn;
    int days = daysBill + daysJohn;

    int totalMinutes = minutes % MINUTES_PER_HOUR;
    minutes -= totalMinutes;

    int totalHours = (hours + (minutes / MINUTES_PER_HOUR)) % HOURS_PER_DAY;
    hours -= totalHours;

    int totalDays = days + (hours / HOURS_PER_DAY);

    std::cout << "The total time both of them worked together is: ";
    std::cout << totalDays << " days, ";
    std::cout << totalHours << " hours and ";
    std::cout << totalMinutes << " minutes.";

    return 0;
}
