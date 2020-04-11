#include <iostream>

int main() {
    int numQuarters, numDimes, numNickels, numPennies;

    std::cout << "Please enter number of coins:" << std::endl;
    std::cout << "# of quarters:" << std::endl;
    std::cin >> numQuarters;
    std::cout << "# of dimes:" << std::endl;
    std::cin >> numDimes;
    std::cout << "# of nickels:" << std::endl;
    std::cin >> numNickels;
    std::cout << "# of pennies:" << std::endl;
    std::cin >> numPennies;

    int totalCents =  numQuarters * 25 + numDimes * 10 + numNickels * 5 + numPennies;
    int dollars = totalCents / 100;
    int cents = totalCents % 100;

    std::cout << "The total is " << dollars << " dollars and " << cents << " cents";

    return 0;
}
