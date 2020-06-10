#include <algorithm>
#include <iostream>
using std::string;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    std::cout << "Type in a sentence:" << std::endl;

    string sentence;
    std::getline (std::cin, sentence);

    int wordCount = 0;

    string *words = createWordsArray(sentence, wordCount);

    std::cout << wordCount << std::endl;

    for (int i = 0; i < wordCount; ++i) {
        std::cout << words[i] << std::endl;
    }

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    string word = "";
    int spaceCount = std::count(sentence.begin(), sentence.end(), ' ');
    int sentenceLength = sentence.length();
    string *wordArray = new string[spaceCount + 2];

    for (int i = 0; i <= sentenceLength; ++i) {
        if ( i == sentenceLength ){
            std::cout << i << std::endl;
            wordArray[outWordsArrSize++] = word;
            break;
        }

        char character = sentence[i];
        if (character == ' ') {
            wordArray[outWordsArrSize++] = word;
            word = "";
        } else {
            word = word + character;
        }
    }

    return wordArray;
}