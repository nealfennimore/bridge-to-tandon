#include <iostream>

void whileLoop(int n);

void forLoop(int n);

int main() {
    int n;

    std::cout << "Please enter a positive integer: ";
    std::cin >> n;

    whileLoop(n);
    forLoop(n);

    return 0;
}

void whileLoop(int n) {
    std::cout << "Printing even in a while loop:" << std::endl;
    int i = 1;
    while ( i <= n ) {
        std::cout << i * 2 << std::endl;
        i++;
    }
}

void forLoop(int n) {
    std::cout << "Printing even in a for loop:" << std::endl;
    for ( int i = 1; i <= n; i++ ) {
        std::cout << i * 2 << std::endl;
    }
}