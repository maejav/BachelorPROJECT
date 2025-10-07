#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

const int MAX_SIZE = 15;
int grid[MAX_SIZE][MAX_SIZE];     // Actual game grid: 0 = bomb, 1 = safe, 2 = flagged
char display[MAX_SIZE][MAX_SIZE]; // Player-visible grid
int gridSize, minBombs, maxBombs, bombCount, revealedCells;

void initializeGrid() {
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
            grid[i][j] = 1;
}

void placeBombs() {
    int bombsToPlace = rand() % (maxBombs - minBombs + 1) + minBombs;
    bombCount = bombsToPlace;

    while (bombsToPlace > 0) {
        int x = rand() % gridSize;
        int y = rand() % gridSize;
        if (grid[x][y] == 1) {
            grid[x][y] = 0;
            bombsToPlace--;
        }
    }
}

void initializeDisplay() {
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
            display[i][j] = '*';
}

void showDisplayGrid() {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++)
            cout << display[i][j] << " ";
        cout << "\n";
    }
}

void showActualGrid() {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

int countAdjacentBombs(int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < gridSize && j >= 0 && j < gridSize && !(i == row && j == col)) {
                if (grid[i][j] == 0)
                    count++;
            }
        }
    }
    return count;
}

int main() {
    srand(time(0));
    char playAgain = 'y';

    while (playAgain == 'y') {
        int difficulty;
        cout << "Select difficulty level:\n";
        cout << "1 = Easy\n2 = Medium\n3 = Hard\n";
        cin >> difficulty;
        system("cls");

        if (difficulty == 1) { gridSize = 5; maxBombs = 10; minBombs = 1; }
        else if (difficulty == 2) { gridSize = 10; maxBombs = 20; minBombs = 10; }
        else if (difficulty == 3) { gridSize = 15; maxBombs = 30; minBombs = 20; }

        initializeGrid();
        placeBombs();
        initializeDisplay();
        revealedCells = 0;
        int totalSafeCells = gridSize * gridSize - bombCount;

        while (true) {
            showDisplayGrid();
            cout << "\nChoose an action:\n1 = Reveal cell\n2 = Flag bomb\n";
            int action, row, col;
            cin >> action;

            cout << "Enter row and column (0 to " << gridSize - 1 << "): ";
            cin >> row >> col;

            if (row < 0 || row >= gridSize || col < 0 || col >= gridSize) {
                cout << "Invalid coordinates!\n";
                continue;
            }

            if (action == 1) {
                if (grid[row][col] == 0) {
                    system("cls");
                    cout << "You hit a bomb! Game over.\n";
                    showActualGrid();
                    break;
                } else {
                    int adjacent = countAdjacentBombs(row, col);
                    display[row][col] = adjacent + '0';
                    revealedCells++;
                    system("cls");
                    if (revealedCells == totalSafeCells) {
                        cout << "Congratulations! You revealed all safe cells.\n";
                        showDisplayGrid();
                        break;
                    }
                }
            } else if (action == 2) {
                if (grid[row][col] == 1) {
                    system("cls");
                    cout << "Incorrect flag! That was a safe cell. Game over.\n";
                    showActualGrid();
                    break;
                } else if (grid[row][col] == 0) {
                    bombCount--;
                    grid[row][col] = 2;
                    display[row][col] = 'F';
                    system("cls");
                    if (bombCount == 0) {
                        cout << "You flagged all bombs correctly! You win!\n";
                        showDisplayGrid();
                        break;
                    }
                }
            }
        }

        cout << "Play again? Enter 'y' to restart or any other key to exit: ";
        cin >> playAgain;
        system("cls");
    }

    return 0;
}
