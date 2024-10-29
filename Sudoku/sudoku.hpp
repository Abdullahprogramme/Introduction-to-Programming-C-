#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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

// Function to print the Sudoku board
void print_board(const array<array<int, 9>, 9>& board) {
    cout << "Current state of the board:" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6) {
                cout << " | ";
            }
            cout << board[i][j] << " ";
        }
        if (i == 2 || i == 5) {
            cout << endl << "-----------------------";
        }
        cout << endl;
    }
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

// Function to check if the board is fully filled
bool is_board_full(const array<array<int, 9>, 9>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Function to delete a cell (set to 0)
array<array<int, 9>, 9> delete_cell(array<array<int, 9>, 9> board, int row, int col) {
    // To ensure only player-entered numbers are deleted, you may need to store the "original" cells
    board[row][col] = 0;
    return board;
}

// Function to generate a valid Sudoku board using backtracking
bool solve_sudoku(array<array<int, 9>, 9>& board, int row, int col) {
    if (row == 9) return true; // Solved the board
    if (col == 9) return solve_sudoku(board, row + 1, 0); // Move to the next row
    if (board[row][col] != 0) return solve_sudoku(board, row, col + 1); // Skip filled cells

    // Create a shuffled vector of numbers 1-9 to introduce randomness
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    random_shuffle(numbers.begin(), numbers.end());

    for (int num : numbers) {
        if (is_safe(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board, row, col + 1)) {
                return true;
            }
            board[row][col] = 0; // Backtrack if the placement doesn't work
        }
    }

    return false;
}

// Function to create a valid partially filled Sudoku board
array<array<int, 9>, 9> make_partial_board() {
    srand(time(0));

    array<array<int, 9>, 9> board = {0};

    // Generate a complete, valid Sudoku board
    solve_sudoku(board, 0, 0);

    // Remove random values to make it a partial board
    int cells_to_remove = 40 + rand() % 10; // Remove between 40 and 50 cells

    while (cells_to_remove > 0) {
        int row = rand() % 9;
        int col = rand() % 9;

        if (board[row][col] != 0) {
            board[row][col] = 0; // Remove the value
            cells_to_remove--;
        }
    }

    return board;
}
