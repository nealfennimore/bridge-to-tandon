#include <iostream>
#include <cmath>
using std::string;

int main() {
    int n;
    std::cout << "Please enter a positive integer:" << std::endl;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << i * j << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}