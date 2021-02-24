#include <iostream>

double productCache = 1;
double eApprox(int n);

int main() {
    std::cout.precision(30);
    double e = 0;
    for (int n = 0; n <= 14; n++) {
        e += eApprox(n);
        std::cout << "n = " << n << '\t' << e << " productCache " << productCache << std::endl;
    }
    return 0;
}

double eApprox(int n) {
    if(n < 2){
        return static_cast<double>(1);
    }
    productCache *= n;
    return 1 / productCache;
}