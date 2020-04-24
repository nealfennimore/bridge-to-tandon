#include <iostream>
#include <vector>

using std::pair, std::string, std::vector;

vector< pair<int, string> > ROMAN_NUMERALS_LIST{
    std::make_pair(1000, "M"),
    std::make_pair(500, "D"),
    std::make_pair(100, "C"),
    std::make_pair(50, "L"),
    std::make_pair(10, "X"),
    std::make_pair(5, "V"),
    std::make_pair(1, "I"),
};

int main() {
    int decimal, originalDecimal;
    string romanNumerals;

    std::cout << "Please decimal number:" << std::endl;
    std::cin >> decimal;

    originalDecimal = decimal;

    for (int i = 0; i < ROMAN_NUMERALS_LIST.size(); ++i) {

        pair<int, string> item = ROMAN_NUMERALS_LIST[i];
        int numeralAmount = item.first;
        string numeral = item.second;

        if( decimal >= numeralAmount ) {
            int quotient = decimal / numeralAmount;

            for (int j = 0; j < quotient; ++j) {
                romanNumerals.append(numeral);
            }

            decimal -= (quotient * numeralAmount);
        }
    }

    std::cout << originalDecimal << " is: " << romanNumerals;

    return 0;
}