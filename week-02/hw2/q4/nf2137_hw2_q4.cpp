#include <iostream>

int main() {
    int numOne, numTwo;

    std::cout << "Please enter two positive integers, separated by a space:" << std::endl;
    std::cin >> numOne;
    std::cin >> numTwo;

    int sum = numOne + numTwo;
    int difference = numOne - numTwo;
    int product = numOne * numTwo;
    float quotient = (float)(numOne) / numTwo;
    int div = numOne / numTwo;
    int remainder = numOne % numTwo;

    std::cout << numOne << " + " << numTwo << " = " << sum << std::endl;
    std::cout << numOne << " - " << numTwo << " = " << difference << std::endl;
    std::cout << numOne << " * " << numTwo << " = " << product << std::endl;
    std::cout << numOne << " / " << numTwo << " = " << quotient << std::endl;
    std::cout << numOne << " div " << numTwo << " = " << div << std::endl;
    std::cout << numOne << " mod " << numTwo << " = " << remainder << std::endl;

    return 0;
}
