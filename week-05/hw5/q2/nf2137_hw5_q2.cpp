#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;

    int lower = 1, higher = 100, numGuesses = 5;

    std::cout << "I thought of a number between 1 and 100! Try to guess it." << std::endl;

    while( numGuesses > 0 ){
        std::cout << "Range: [" << lower << ", " << higher << "], Number of guesses left: " << numGuesses << std::endl;
        std::cout << "Your guess: " << std::endl;

        int guess;
        std::cin >> guess;

        if( guess == randomNumber ){
            std::cout << "Congrats! You guessed my number in " << 5 - numGuesses << " guesses.";
            break;
        } else if ( guess < randomNumber && numGuesses > 1 ) {
            lower = guess + 1;
            std::cout << "Wrong! My number is bigger." << std::endl;
        } else if ( guess > randomNumber && numGuesses > 1 ) {
            higher = guess - 1;
            std::cout << "Wrong! My number is smaller." << std::endl;
        }
        numGuesses--;
    }

    if (numGuesses == 0 ){
        std::cout << "Out of guesses! My number is " << randomNumber;
    }

    return 0;
}