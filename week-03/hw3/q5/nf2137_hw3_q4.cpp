#include <iostream>
#include <cmath>
using std::string;

int main() {
    double weightInPounds, heightInInches, weightInKilograms, heightInMeters, bmi;
    string weightStatus;

    std::cout << "Please enter weight (in pounds): " << std::endl;
    std::cin >> weightInPounds;

    std::cout << "Please enter height (in inches): " << std::endl;
    std::cin >> heightInInches;

    weightInKilograms = weightInPounds * 0.453592;
    heightInMeters = heightInInches * 0.0254;
    bmi = weightInKilograms / pow(heightInMeters, 2);

    if (bmi >= 30) {
        weightStatus = "Obese";
    } else if (bmi < 30 && bmi >= 25 ) {
        weightStatus = "Overweight";
    } else if (bmi < 25 && bmi >= 18.5 ) {
        weightStatus = "Normal";
    } else if (bmi < 18.5 ) {
        weightStatus = "Underweight";
    }

    std::cout << "The weight status is: " << weightStatus << std::endl;

    return 0;
}
