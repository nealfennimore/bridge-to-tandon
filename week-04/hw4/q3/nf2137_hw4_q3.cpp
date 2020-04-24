#include <iostream>
using std::string, std::to_string;

int main() {
    int n, original;
    string binary;

    std::cout << "Enter decimal number: ";
    std::cin >> n;

    original = n;

    for( int i = 0; n > 0; i++) {
        binary.insert( 0, to_string( n % 2 ) );
        n /= 2;
    }

    std::cout << "The binary representation of " << original << " is " << binary;

    return 0;
}