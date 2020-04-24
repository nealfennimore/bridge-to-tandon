#include <iostream>
#include <cmath>

void sequenceWithLength();
void sequenceThatStopsOnNegativeOne();

int main() {

    sequenceWithLength();
    sequenceThatStopsOnNegativeOne();

    return 0;
}

void sequenceWithLength() {
    int length;
    double product = 1.0;

    std::cout << "Please enter the length of the sequence: " << std::endl;
    std::cin >> length;

    std::cout << "Please enter your sequence" << std::endl;

    for (int i = 0; i < length; ++i) {
        double element;
        std::cin >> element;
        product *= element;
    }

    std::cout << "The geometric mean is: " << pow(product, 1.0 / length) << std::endl;
}

void sequenceThatStopsOnNegativeOne() {
    int length = 0;
    double product = 1.0;
    double last;

    std::cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your" << std::endl << "sequence by typing -1: " << std::endl;

    while( true ) {
        double element;
        std::cin >> element;
        if ( element == -1 ) {
            break;
        }
        product *= element;
        length++;
    }

    std::cout << "The geometric mean is: " << pow(product, 1.0 / length);
}