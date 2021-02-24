#include <iostream>
#include <string>
using std::string;

bool isPalindrome(string str);

int main() {
    string word;
    std::cout << "Please enter a word:" << std::endl;
    std::cin >> word;

    bool valid = isPalindrome(word);

    std::cout << word << " is " << (valid ? "" : "not ") << "a palindrome";

    return 0;
}

bool isPalindrome(string str) {
    int size = str.size();
    for (int i = 0; i < size / 2; ++i) {
        if ( str[i] != str[size - 1 - i]){
            return false;
        }
    }
    return true;
}