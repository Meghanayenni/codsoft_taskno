#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a random number between 1 and 100." << endl;
    cout << "Your task is to guess the number." << endl;
    do {      
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;
        if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number!" << endl;
            cout << "It took you " << attempts << " attempts to guess the number." << endl;
        }
    } while (userGuess != randomNumber); 

    return 0;
}
