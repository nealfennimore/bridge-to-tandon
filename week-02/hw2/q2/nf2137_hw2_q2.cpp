#include <iostream>

int main() {
    int dollars, cents;

    std::cout << "Please enter your amount in the format of dollars and cents separated by a space:" << std::endl;
    std::cin >> dollars;
    std::cin >> cents;

    int totalCents = dollars * 100 + cents;

    int numQuarters = totalCents / 25;
    totalCents -= numQuarters * 25;

    int numDimes = totalCents / 10;
    totalCents -= numDimes * 10;

    int numNickels = totalCents / 5;
    totalCents -= numNickels * 5;

    int numPennies = totalCents;

    std::cout << dollars << " dollars and " << cents << " cents are:" << std::endl;
    std::cout << numQuarters << " quarters, ";
    std::cout << numDimes << " dimes, ";
    std::cout << numNickels << " nickels, ";
    std::cout << numPennies << " pennies";

    return 0;
}
