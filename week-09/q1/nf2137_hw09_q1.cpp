#include <iostream>
#include <string>
#include <map>
using std::string, std::map, std::pair;



int main() {
    std::cout << "Please enter a line of text:" << std::endl;
    //string text = "I Say Hi.";
    string text;
    std::getline (std::cin,text);

    int wordCount = 0;
    int lastAlphaNumericIndex = 0;

    map<char, int> letters;

    for (int i = 0; i < text.size(); ++i) {
        char item = tolower(text[i]);

        if ( isalpha(item) ) {
            lastAlphaNumericIndex = i;
            map<char, int>::iterator letter = letters.find(item);
            if( letter != letters.end() ) {
                letter->second += 1;
            } else {
                letters.insert( pair<char, int>( item, 1) );
            }
            continue;
        }

        if ( isblank(item) || ispunct(item) ) {
            if ( lastAlphaNumericIndex == i - 1 ){
                wordCount++;
            }
            continue;
        }
    }

    std::cout << wordCount << " words" << std::endl;

    map<char, int>::iterator it;
    for (it = letters.begin(); it != letters.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}