#include <iostream>
#include <cmath>
#include <vector>;
using std::vector;

void printDivisors(int n);

int main() {
    int n;
    std::cout << "Please enter a positive integer >= 2:" << std::endl;
    std::cin >> n;
    printDivisors(n);
}

void printDivisors(int n)
{
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++) {
        if ( n % i == 0) {
            if ( n / i == i ) {
                std::cout << i << " ";
            } else {
                std::cout << i << " ";
                v.push_back( n / i );
            }
        }
    }

    for (int i=v.size()-1; i>=0; i--) {
        std::cout << v[i] << " ";
    }
}