#include <iostream>
#include <cmath>
using std::string;

int fib(int n);

int main() {
    int n;
    std::cout << "Please enter a positive number:" << std::endl;
    std::cin >> n;

    std::cout << fib(n);

    return 0;
}

int fib(int n) {
    if (n <= 2){
        return 1;
    }

    if ( n == 3 ){
        return 2;
    }

    int count = 4, a = 1, b = 2;

    while( count < n ){
        int temp = b;
        b = a + b;
        a = temp;
        count++;
    }

    return a + b;
}