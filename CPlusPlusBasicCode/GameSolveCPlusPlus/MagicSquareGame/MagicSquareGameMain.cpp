#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to generate an odd-order magic square
vector<vector<int>> generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int num = 1;
    int row = 0;
    int col = n / 2;

    while (num <= n * n) {
        magicSquare[row][col] = num++;

        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        if (magicSquare[nextRow][nextCol] != 0) {
            row = (row + 1) % n;
        } else {
            row = nextRow;
            col = nextCol;
        }
    }

    return magicSquare;
}

int main() {
    int n;
    cout << "Enter an odd number for the size of the magic square: ";
    cin >> n;

    if (n % 2 == 0 || n <= 0) {
        cout << "Only positive odd numbers are allowed.\n";
        return 1;
    }

    vector<vector<int>> magicSquare = generateMagicSquare(n);

    cout << "\nMagic Square of size " << n << ":\n\n";
    for (const auto& row : magicSquare) {
        for (int val : row) {
            cout << setw(4) << val;
        }
        cout << "\n";
    }

    return 0;
}
