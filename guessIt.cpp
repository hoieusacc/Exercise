#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playGame() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;
    char playAgain;
    do {
        cout << "Guess the number (1 to 100): ";
        cin >> guess;
        attempts++;
        if (guess < number) {
            cout << "Too low! Try again.\n";
        } else if (guess > number) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
            cout << "Your score: " << 100 - attempts << "\n";
            break;
        }
    } while (guess != number);
    
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();
    }
}

int main() {
    playGame();
    return 0;
}
