#include <iostream>
#include <cmath>
using std::string;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {

    printShiftedTriangle(3, 4, '+');

    std::cout << std::endl;

    printPineTree(3, '#');

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 0; i < n; i++) {
        int symbolCount = i * 2 + 1;
        int padLeft = n - 1 - i + m;
        std::cout << string(padLeft, ' ') << string(symbolCount, symbol) << std::endl;
    }
}

void printPineTree(int n, char symbol) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 2; ++j) {
            int symbolCount = j * 2 + 1;
            int padLeft = n - j;
            std::cout << string(padLeft, ' ') << string(symbolCount, symbol) << std::endl;
        }
    }
}