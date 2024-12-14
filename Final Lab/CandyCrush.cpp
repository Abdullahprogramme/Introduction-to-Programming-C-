#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to replace 3 or more consecutive candies of the same type in a row or column with negated values
void crush(vector<vector<int>> &board);

int main() {
    vector<vector<int>> board = {
        {1, 1, 2, 2},
        {3, 1, 3, 3},
        {1, 1, 3, 3},
        {1, 1, 1, 3}
    };

    // Expected output: 1 -1 2 2
    //                  3 -1 3 -3
    //                  1 -1 3 -3
    //                  -1 -1 -1 -3
    crush(board);

    for (const vector<int> &row : board) {
        for (int val : row) {
            cout << setw(2) << val << " ";
        }
        cout << endl;
    }

    return 0;
}

void crush(vector<vector<int>> &board) {
    int rows = board.size();
    int cols = board[0].size();

    // Create a copy of the board to mark cells to be crushed
    vector<vector<bool>> toCrush(rows, vector<bool>(cols, false));

    // Mark candies to be crushed in rows
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 2; j++) {
            int val = abs(board[i][j]);
            if (val != 0 && val == abs(board[i][j + 1]) && val == abs(board[i][j + 2])) {
                for (int k = j; k < cols && abs(board[i][k]) == val; k++) {
                    toCrush[i][k] = true;
                }
            }
        }
    }

    // Mark candies to be crushed in columns
    for (int i = 0; i < rows - 2; i++) {
        for (int j = 0; j < cols; j++) {
            int val = abs(board[i][j]);
            if (val != 0 && val == abs(board[i + 1][j]) && val == abs(board[i + 2][j])) {
                for (int k = i; k < rows && abs(board[k][j]) == val; k++) {
                    toCrush[k][j] = true;
                }
            }
        }
    }

    // Replace marked cells with their negated values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (toCrush[i][j]) {
                board[i][j] = -abs(board[i][j]); // Negate the value
            }
        }
    }
}
