#include <iostream>
#include <array>

using namespace std;

// Function to check if a number can be placed in the row
bool check_row(const array<array<int, 9>, 9>& board, int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    return true;
}

// Function to check if a number can be placed in the column
bool check_col(const array<array<int, 9>, 9>& board, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    return true;
}

// Function to check if a number can be placed in the 3x3 subgrid
bool check_three_by_three_box(const array<array<int, 9>, 9>& board, int row, int col, int num) {
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + start_row][j + start_col] == num) {
                return false;
            }
        }
    }
    return true;
}

// Combined function to check if placing a number is safe
bool is_safe(const array<array<int, 9>, 9>& board, int row, int col, int num) {
    return check_row(board, row, num) &&
           check_col(board, col, num) &&
           check_three_by_three_box(board, row, col, num);
}

// Function to check each value int the provided board
bool validate_board(array<array<int, 9>, 9>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != 0) {
                int num = board[i][j];
                board[i][j] = 0;
                if (!is_safe(board, i, j, num)) {
                    return false;
                }
                board[i][j] = num;
            }
        }
    }
    return true;
}