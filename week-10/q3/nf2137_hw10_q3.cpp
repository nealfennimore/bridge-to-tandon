#include <iostream>
#include <vector>

using std::vector, std::string;

void withoutVector() {
    std::cout << "Please enter a sequence of positive integers, each in a separate line." << std::endl;
    std::cout << "End you input by typing -1." << std::endl;

    int input;
    string inputs;

    while ( input >= 0 ){
        std::cin >> input;
        inputs += std::to_string(input) + " ";
    }

    int search;
    std::cout << "Please enter a number you want to search." << std::endl;
    std::cin >> search;

    std::cout << search << " shows in lines ";

    string found;
    string integer;
    int lineCount = 1;
    for (int i = 0; i < inputs.size(); ++i) {
        if (inputs[i] == ' '){
            if( std::stoi(integer) == search ){
                found += std::to_string(lineCount) + ",";
            }
            lineCount++;
            integer = "";
        } else {
            integer += inputs[i];
        }
    }

    found.pop_back();
    std::cout << found << "." << std::endl;
}

void withVector() {
    std::cout << "Please enter a sequence of positive integers, each in a separate line." << std::endl;
    std::cout << "End you input by typing -1." << std::endl;

    int input;
    vector<int> inputs;

    while ( input >= 0 ){
        std::cin >> input;
        inputs.push_back(input);
    }

    int search;
    std::cout << "Please enter a number you want to search." << std::endl;
    std::cin >> search;

    std::cout << search << " shows in lines ";

    string found;
    for (int i = 0; i < inputs.size(); ++i) {
        if (inputs[i] == search) {
            found += std::to_string(i + 1) + ",";
        }
    }

    found.pop_back();
    std::cout << found << "." << std::endl;
}

int main() {

    std::cout << "***** without vectors *****" << std::endl;
    withoutVector();

    std::cout << "***** with vectors *****" << std::endl;
    withVector();

    return 0;
}
