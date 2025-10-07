#include <iostream>
#include <cstdlib>
using namespace std;

int initialBoard[9][9] = {
    {6,8,3,9,4,1,2,0,0},
    {0,2,5,7,0,3,4,6,0},
    {0,0,9,0,6,0,8,1,3},
    {7,6,0,0,3,0,0,8,5},
    {9,0,1,6,0,8,7,0,2},
    {3,5,8,1,0,7,0,0,4},
    {0,9,0,5,1,0,0,4,6},
    {5,1,4,3,7,0,9,2,8},
    {2,0,0,0,9,4,5,7,0}
};

class SudokuNode {
public:
    int board[9][9];
    int candidates[9];
    int candidateIndex;
    SudokuNode* next;

    SudokuNode() {
        for (int i = 0; i < 9; i++)
            candidates[i] = i + 1;
        candidateIndex = 0;
        next = nullptr;
    }

    friend class SudokuSolver;
};

class SudokuSolver {
private:
    SudokuNode* root;
    SudokuNode* current;

public:
    SudokuSolver() {
        root = new SudokuNode();
        current = root;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                root->board[i][j] = initialBoard[i][j];
    }

    void displayBoard() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << current->board[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }

    int countEmptyCells() {
        int count = 0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (current->board[i][j] == 0)
                    count++;
        return count;
    }

    void findNextEmpty(int& row, int& col) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (current->board[i][j] == 0) {
                    row = i;
                    col = j;
                    return;
                }
    }

    bool isValid(int row, int col, int value) {
        for (int i = 0; i < 9; i++) {
            if (i != col && current->board[row][i] == value) return false;
            if (i != row && current->board[i][col] == value) return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
            for (int j = startCol; j < startCol + 3; j++)
                if ((i != row || j != col) && current->board[i][j] == value)
                    return false;

        return true;
    }

    void backtrack() {
        if (current == root) {
            cout << "No solution found.\n";
            exit(0);
        }

        SudokuNode* toDelete = current;
        SudokuNode* prev = root;
        while (prev->next != current)
            prev = prev->next;

        current = prev;
        delete toDelete;
        current->next = nullptr;

        current->candidates[current->candidateIndex] = 0;

        bool hasCandidates = false;
        for (int i = 0; i < 9; i++)
            if (current->candidates[i] != 0)
                hasCandidates = true;

        if (!hasCandidates)
            backtrack();
    }

    void solve() {
        displayBoard();

        while (countEmptyCells() > 0) {
            int row, col;
            findNextEmpty(row, col);

            current->next = new SudokuNode();
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    current->next->board[i][j] = current->board[i][j];

            int value = 0;
            for (int i = 0; i < 9; i++) {
                if (current->candidates[i] != 0) {
                    value = current->candidates[i];
                    current->next->board[row][col] = value;
                    current->candidateIndex = i;
                    break;
                }
            }

            current = current->next;
            displayBoard();

            if (isValid(row, col, value)) {
                continue;
            } else {
                backtrack();
            }
        }

        cout << "Sudoku solved successfully!\n";
        displayBoard();
    }
};

int main() {
    SudokuSolver solver;
    solver.solve();
    return 0;
}
