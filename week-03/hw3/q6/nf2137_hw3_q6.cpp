#include <iostream>
#include <cmath>
using std::string, std::stof;

int main() {
    string dayOfWeek, startTime;
    float numOfMinutes, callRate;

    std::cout << "Please enter day of week: " << std::endl;
    std::cin >> dayOfWeek;

    std::cout << "Please enter start time: " << std::endl;
    std::cin >> startTime;

    std::cout << "Please enter how long the call was: " << std::endl;
    std::cin >> numOfMinutes;

    if ( dayOfWeek == "Sa" || dayOfWeek == "Su") {
        callRate = 0.15;
    } else {
        size_t index = startTime.find(":");

        float hour = stof( startTime.substr(0, index) );
        float minute = stof( startTime.substr(index + 1) );

        if ( (hour >= 8 && hour < 18) || (hour == 18 && minute == 0 ) ){
            callRate = 0.40;
        } else {
            callRate = 0.25;
        }
    }

    std::cout << "Cost of the call: $" <<  (numOfMinutes * callRate) << std::endl;

    return 0;
}
