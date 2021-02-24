#include <iostream>
#include <string>
#include <regex>
#include <vector>
using std::string, std::vector, std::pair, std::make_pair, std::replace;

int main() {
    std::cout << "Enter some text:" << std::endl;
    string text;
    std::getline (std::cin,text);
    string clone = text;

    int firstDigitIndex = -1;
    int firstSpaceIndex = -1;
    for (int i = 0; i < text.size(); ++i) {
        char item = text[i];

        if ( isalpha(item) ) {
            firstDigitIndex = -1;
            continue;
        }

        if ( isdigit(item) && firstDigitIndex == -1 && firstSpaceIndex == i - 1 ) {
            firstDigitIndex = i;
            continue;
        }

        if ( isblank(item) ) {
            if ( firstDigitIndex >= 0 ) {
                int numChars = i - firstDigitIndex;
                clone.replace(firstDigitIndex, numChars, numChars, 'x');
                firstDigitIndex = -1;
            }
            firstSpaceIndex = i;
            continue;
        }
    }

    std::cout << clone;

    return 0;
}
