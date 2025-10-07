#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Position {
    int row, col;
};

class Stack {
    vector<Position> data;

public:
    void push(int row, int col) {
        data.push_back({row, col});
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    Position top() const {
        if (!data.empty()) {
            return data.back();
        }
        return {-1, -1}; // Invalid position
    }

    bool empty() const {
        return data.empty();
    }

    void print() const {
        cout << "\nPath through the maze:\n";
        for (size_t i = 0; i < data.size(); ++i) {
            cout << i + 1 << ": (" << data[i].row << ", " << data[i].col << ")\n";
        }
    }
};

vector<vector<int>> maze;
vector<vector<bool>> visited;

bool isValid(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows &&
           col >= 0 && col < cols &&
           maze[row][col] == 0 &&
           !visited[row][col];
}

bool solveMaze(int startRow, int startCol, int endRow, int endCol, Stack& path) {
    int rows = maze.size();
    int cols = maze[0].size();
    path.push(startRow, startCol);
    visited[startRow][startCol] = true;

    while (!path.empty()) {
        Position current = path.top();

        if (current.row == endRow && current.col == endCol) {
            return true;
        }

        bool moved = false;
        vector<Position> directions = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1},
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };

        for (const auto& dir : directions) {
            int newRow = current.row + dir.row;
            int newCol = current.col + dir.col;

            if (isValid(newRow, newCol, rows, cols)) {
                path.push(newRow, newCol);
                visited[newRow][newCol] = true;
                moved = true;
                break;
            }
        }

        if (!moved) {
            path.pop();
        }
    }

    return false;
}

bool loadMaze(const string& filename, int& rows, int& cols) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << "\n";
        return false;
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    rows = lines.size() + 2;
    cols = 0;
    for (char ch : lines[0]) {
        if (ch != ' ') ++cols;
    }
    cols += 2;

    maze.assign(rows, vector<int>(cols, 1));
    visited.assign(rows, vector<bool>(cols, false));

    for (size_t i = 0; i < lines.size(); ++i) {
        int colIndex = 1;
        for (char ch : lines[i]) {
            if (ch != ' ') {
                maze[i + 1][colIndex++] = ch - '0';
            }
        }
    }

    cout << "\nMaze loaded (" << rows << "x" << cols << "):\n";
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }

    return true;
}

int main() {
    int rows, cols;
    if (!loadMaze("t.txt", rows, cols)) {
        return 1;
    }

    Stack path;
    int startRow = 1, startCol = 1;
    int endRow = rows - 2, endCol = cols - 2;

    if (maze[startRow][startCol] != 0 || maze[endRow][endCol] != 0) {
        cerr << "Error: Start or end position is blocked.\n";
        return 1;
    }

    if (solveMaze(startRow, startCol, endRow, endCol, path)) {
        path.print();
    } else {
        cout << "No path found through the maze.\n";
    }

    cout << "\nProgram finished.\n";
    return 0;
}
