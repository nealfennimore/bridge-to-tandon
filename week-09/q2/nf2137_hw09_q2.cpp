#include <algorithm>

#include <iostream>
#include <string>
using std::string;

bool isAnagram(string a, string b);

int main() {
    std::cout << "Please enter a line of text:" << std::endl;
    string text;
    std::getline (std::cin,text);

    std::cout << "Please enter a second line of text:" << std::endl;
    string text1;
    std::getline (std::cin,text1);

    // Convert to text lowercase for valid comparison
    std::for_each(text.begin(), text.end(), [](char & c) {
        c = ::tolower(c);
    });
    std::for_each(text1.begin(), text1.end(), [](char & c) {
        c = ::tolower(c);
    });

    bool anagram = isAnagram(text, text1);

    std::cout << "Items are " << (anagram ? "" : "not ") << "anagrams.";

    return 0;
}


bool isAnagram(string a, string b) {
    string biggerString = a.size() < b.size() ? b : a;

    for (int i = 0; i < biggerString.size(); ++i) {
        char item = tolower(biggerString[i]);

        if ( isalpha(item) ) {
            size_t n = std::count(a.begin(), a.end(), item);
            size_t n1 = std::count(b.begin(), b.end(), item);

            if (n != n1) {
                return false;
            }
        }
    }

    return true;
}