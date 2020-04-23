#include <iostream>
#include <cmath>

int main() {
    float a, b, c, x1, x2, discriminant;

    std::cout << "Please enter the value of a:" << std::endl;
    std::cin >> a;
    std::cout << "Please enter the value of b:" << std::endl;
    std::cin >> b;
    std::cout << "Please enter the value of c:" << std::endl;
    std::cin >> c;

    discriminant = b*b - 4*a*c;

    if (a != 0 && discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        std::cout << "The equation has a two real solutions: x1 = " << x1  << " and x2 = " << x2 << std::endl;
    } else if (a != 0 && discriminant == 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        std::cout << "The equation has a single real solution x = " << x1 << std::endl;
    } else {
        std::cout << "The equation has no solution."  << std::endl;
    }

    return 0;
}
