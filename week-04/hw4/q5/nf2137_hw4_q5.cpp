#include <iostream>
using std::string;

void print(int n, int i);

int main() {
    int n;

    std::cout << "Please enter a positive integer: " << std::endl;
    std::cin >> n;

    for (int i = n - 1; i >= 0; i--) {
        print(n, i);
    }
    for (int i = 0; i < n; i++) {
        print(n, i);
    }

    return 0;
}

void print(int n, int i) {
    int asteriskCount = i * 2 + 1;
    int padLeft = n - i;
    std::cout << string(padLeft, ' ') << string(asteriskCount, '*') << std::endl;
}