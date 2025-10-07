#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

const int BOARD_SIZE = 8;
int row, col;

void showKnightMoves() {
    int moves[8][2] = {
        {-2, +1}, {-2, -1}, {+2, +1}, {+2, -1},
        {-1, -2}, {+1, -2}, {-1, +2}, {+1, +2}
    };

    cout << "Valid knight moves from (" << row << ", " << col << "):\n";
    for (int i = 0; i < 8; i++) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) {
            cout << "→ (" << newRow << ", " << newCol << ")\n";
        }
    }
}

int main() {
    char continueGame = 'y';

    while (continueGame == 'y') {
        system("cls");
        cout << "Enter knight's position (row and column from 0 to 7): ";
        cin >> row >> col;

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            cout << "Invalid position! Press any key to try again...\n";
            getch();
            continue;
        }

        showKnightMoves();

        cout << "\nDo you want to continue? (y/n): ";
        cin >> continueGame;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
