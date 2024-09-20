// Random generator

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(0)));
    // Generate a random number between 1 and 100
    int random = rand() % 100 + 1;
    
    int userGuess;
    cout << "Guess a number between 1 and 100: ";
    cin >> userGuess;

    while (userGuess != random) {
        if (userGuess > random) {
            cout << "Too high! Try again: ";
        } else {
            cout << "Too low! Try again: ";
        } 
        cin >> userGuess;
    }
    cout << "You guessed it right";
}