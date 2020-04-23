#include <iostream>
using std::string;

int main() {
    string name, status;
    int gradYear, currYear, diffYears;

    std::cout << "Please enter your name:" << std::endl;
    std::cin >> name;
    std::cout << "Please enter your graduation year:" << std::endl;
    std::cin >> gradYear;
    std::cout << "Please enter current year:" << std::endl;
    std::cin >> currYear;

    diffYears = gradYear - currYear;
    switch ( diffYears ) {
        case 4:
            status = "are a Freshmen";
            break;
        case 3:
            status = "are a Sophomore";
            break;
        case 2:
            status = "are a Junior";
            break;
        case 1:
            status = "are a Senior";
            break;
        case 0:
            status = "have graduated";
            break;
        default:
            status = "not in college yet";
    }

    std::cout << name << ", you " << status << std::endl;

    return 0;
}
