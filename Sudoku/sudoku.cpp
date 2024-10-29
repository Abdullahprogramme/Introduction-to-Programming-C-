#include <iostream>
#include <array>
#include <vector>
#include "sudoku.hpp"

using namespace std;

int main() {
    // 0 represents an empty cell
    array<array<int, 9>, 9> board = {
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        }
    };

    // Create a boolean array to track if the cell is modifiable
    array<array<bool, 9>, 9> is_modifiable = {false};

    // Initialize the modifiable array
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                is_modifiable[i][j] = true;  // Only empty cells are modifiable
            }
        }
    }

    print_board(board);

    while (!is_board_full(board)) {
        int row, col, num;
        cout << "Enter row, column, and number (1 - 9) separated by spaces.\n"
             << "If at any point you want to delete a number, enter 0 0 0 for the number: ";
        cin >> row >> col >> num;

        if (row == 0 && col == 0 && num == 0) {
            cout << "Enter the row and column of the cell you want to remove: ";
            cin >> row >> col;

            if (is_modifiable[row - 1][col - 1]) {
                board[row - 1][col - 1] = 0;  // Only delete if it's modifiable
                print_board(board);
            } else {
                cout << "You cannot delete a pre-filled number!" << endl;
            }
            continue;
        }

        if (is_safe(board, row - 1, col - 1, num) && is_modifiable[row - 1][col - 1]) {
            board[row - 1][col - 1] = num;  // Only modify if it's modifiable
        } else {
            cout << "Invalid move!" << endl;
        }
        print_board(board);
    }

    cout << "Congratulations! You solved the puzzle!" << endl;

    return 0;
}
