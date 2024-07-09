#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// create a way to randomly get the play from computer
// opt user to enter their option
// display both options and state winner
// continue playing until user exits game
// display final results with winner


string getComputerChoice() {
    string choices[] = {"rock", "paper", "scissors"};
    return choices[rand() % 3];
}

string getWinner(string player1, string player2) {
    if (player1 == player2) {
        return "Tie";
    } else if ((player1 == "rock" && player2 == "scissors") ||
               (player1 == "paper" && player2 == "rock") ||
               (player1 == "scissors" && player2 == "paper")) {
        return "Player 1";
    } else {
        return "Player 2";
    }
}

int main() {
    srand(time(0)); // Initialize random seed
    string player1;
    string player2;

    int player1Score = 0;
    int player2Score = 0;

    char playAgain;

    do {
        // Get player's choice
        cout << "Enter rock, paper, or scissors: ";
        cin >> player1;

        // Get computer's choice
        player2 = getComputerChoice();
        cout << "Computer chose: " << player2 << endl;

        // Determine the winner
        string winner = getWinner(player1, player2);
        if (winner == "Tie") {
            cout << "It's a tie!" << endl;
        } else if (winner == "Player 1") {
            cout << "You win!" << endl;
            player1Score++;
        } else {
            cout << "Computer wins!" << endl;
            player2Score++;
        }

        // Ask if the player wants to play again
        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    // Display final results
    cout << "Final Scores:" << endl;
    cout << "Player 1: " << player1Score << endl;
    cout << "Computer: " << player2Score << endl;

    if (player1Score > player2Score) {
        cout << "You are the winner!" << endl;
    } else if (player1Score < player2Score) {
        cout << "Computer is the winner!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
