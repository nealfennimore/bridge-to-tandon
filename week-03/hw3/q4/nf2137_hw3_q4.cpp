#include <iostream>
#include <cmath>

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    float realNumber;
    int roundingMethod;

    std::cout << "Please enter a Real number: " << std::endl;
    std::cin >> realNumber;

    std::cout << "Choose your rounding method:" << std::endl;
    std::cout << "1. Floor round" << std::endl;
    std::cout << "2. Ceiling round" << std::endl;
    std::cout << "3. Round to the nearest whole number" << std::endl;
    std::cin >> roundingMethod;

    switch ( roundingMethod ) {
        case 1:
            std::cout << floorf( realNumber );
            break;
        case 2:
            std::cout << ceilf( realNumber );
            break;
        case 3:
            std::cout << roundf( realNumber );
            break;
    }

    return 0;
}
