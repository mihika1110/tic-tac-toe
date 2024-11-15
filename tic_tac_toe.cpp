#include <bits/stdc++.h>
using namespace std;

char square[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int check_win() {
    if (square[0] == square[1] && square[1] == square[2]) {
        if (square[0] == 'X') return 1;
        else return 2;
    }
    else if (square[3] == square[4] && square[4] == square[5]) {
        if (square[3] == 'X') return 1;
        else return 2;
    }
    else if (square[6] == square[7] && square[7] == square[8]) {
        if (square[6] == 'X') return 1;
        else return 2;
    }
    else if (square[0] == square[3] && square[3] == square[6]) {
        if (square[0] == 'X') return 1;
        else return 2;
    }
    else if (square[1] == square[4] && square[4] == square[7]) {
        if (square[1] == 'X') return 1;
        else return 2;
    }
    else if (square[2] == square[5] && square[5] == square[8]) {
        if (square[2] == 'X') return 1;
        else return 2;
    }
    else if (square[0] == square[4] && square[4] == square[8]) {
        if (square[0] == 'X') return 1;
        else return 2;
    }
    else if (square[2] == square[4] && square[4] == square[6]) {
        if (square[2] == 'X') return 1;
        else return 2;
    }
    else return 0; // No winner yet
}

void mark(int player, int box, char symbol) {
    square[box] = symbol;
}

void display() {
    // Display the board with numbers 1 to 9 and replace them with X or O as appropriate
    for (int i = 0; i < 9; i++) {
        cout << square[i] << "\t";
        if (i == 2 || i == 5 || i == 8) cout << endl;
    }
}

int main() {
    string player_1_name, player_2_name;
    int box, result = 0, game_result = 0;
    char player_1_symbol = 'X', player_2_symbol = 'O'; // Default symbols for the players

    cout << "Player 1 enter you name : ";
    cin >> player_1_name;
    cout << "Player 2 enter you name : ";
    cin >> player_2_name;

    // Game loop
    for (int i = 1; i <= 5; i++) {
        // Player 1's turn
        cout << "\n" << player_1_name << "'s turn (symbol: X)" << endl;
        cout << "Enter the box number (1-9): ";
        cin >> box;
        if (box < 1 || box > 9 || square[box - 1] == 'X' || square[box - 1] == 'O') {
            cout << "Invalid move! Please try again." << endl;
            i--;  // Retry the same player's turn
            continue;
        }
        mark(1, box - 1, 'X');
        display();

        result = check_win();
        if (result == 1) {
            cout << "\nCongratulations! " << player_1_name << " has won!" << endl;
            game_result = 1;
            break;
        } else if (result == 2) {
            cout << "\nCongratulations! " << player_2_name << " has won!" << endl;
            game_result = 1;
            break;
        }

        // Player 2's turn
        cout << "\n" << player_2_name << "'s turn (symbol: O)" << endl;
        cout << "Enter the box number (1-9): ";
        cin >> box;
        if (box < 1 || box > 9 || square[box - 1] == 'X' || square[box - 1] == 'O') {
            cout << "Invalid move! Please try again." << endl;
            i--;  // Retry the same player's turn
            continue;
        }
        mark(2, box - 1, 'O');
        display();

        result = check_win();
        if (result == 1) {
            cout << "\nCongratulations! " << player_1_name << " has won!" << endl;
            game_result = 1;
            break;
        } else if (result == 2) {
            cout << "\nCongratulations! " << player_2_name << " has won!" << endl;
            game_result = 1;
            break;
        }
    }

    // Check if it's a draw
    if (game_result == 0) {
        cout << "\nThe game is a draw!" << endl;
    }

    return 0;
}
