#include <iostream>
#include "string"
using std::string;

int main() {
    string first, middle, last;

    std::cout << "Enter your first, middle, and last name" << std::endl;

    std::cin >> first;
    std::cin >> middle;
    std::cin >> last;

    std::cout << last << ", " << first << " " << (middle.at(0)) << ".";

    return 0;
}
