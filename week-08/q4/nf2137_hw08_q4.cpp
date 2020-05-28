#include <iostream>
#include <string>
using std::string;

const int PIN [5] = {1, 2, 3, 4, 5};

int main() {
    srand((unsigned) time(0));
    int seed[10];
    string guess;

    std::cout << "Please enter your PIN according to the following mapping:" << std::endl;
    std::cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "NUM: ";

    for (int i = 0; i < 10; ++i) {
        int item = (rand() % 3) + 1;
        seed[i] = item;
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cin >> guess;

    bool correctPin = true;
    for (int j = 0; j < 5; ++j) {
        int digit = static_cast<int>( guess[j] ) - 48; // Convert back to int. Subtract 48 from ASCII value to get actual digit value

        int pinDigit = PIN[j];
        int seedDigit = seed[pinDigit];

        if (digit != seedDigit){
            correctPin = false;
            break;
        }
    }

    std::cout << "You PIN is " << (correctPin ? "" : "not ") << "correct";

    return 0;
}

