#include <iostream>
using std::string;

void print(int n, int i);

int main() {
    int n;

    std::cout << "Please enter a positive integer: " << std::endl;
    std::cin >> n;

    if (n < 2) {
        std::cout << "No numbers less than 2" << std::endl;
    } else {
        for (int i = 2; i <= n; i += 2) {
            if( i < 10 ){
                std::cout << i << std::endl;
            } else {
                int number = i;
                int evenCount = 0;
                int oddCount = 0;

                while( number > 0 ) {
                    int digit = number % 10;
                    digit % 2 == 0 ? evenCount++ : oddCount++;
                    number /= 10;
                }

                if ( evenCount > oddCount ) {
                    std::cout << i << std::endl;
                }
            }
        }
    }


    return 0;
}