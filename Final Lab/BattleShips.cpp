#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Naval fleet where the arena is 2D grid.
// 'X' represents a ship and '.' represents water.
// Ships are connected horizontally or vertically or diagonally, but no two ships can touch each other in any direction.

// Function to find the number of ships in the naval fleet
int countShips(vector<vector<char>> &grid);

int main() {
    vector<vector<char>> grid = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    }; // Expected output: 2

    cout << countShips(grid) << endl;

    grid = {
        {'X', '.', 'X', '.', '.'},
        {'X', 'X', '.', '.', '.'},
        {'.', '.', '.', 'X', 'X'},
        {'.', '.', '.', 'X', '.'}
    }; // Expected output: 2

    cout << countShips(grid) << endl;

    return 0;
}

int countShips(vector<vector<char>> &grid) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    // Finding ships
    int temp = 0; // should be > 2 to count as a ship
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            // Find ships around (i, j)

            // If ship found, increment count
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < rows && l >= 0 && l < cols && grid[k][l] == 'X') {
                        temp++;
                    }
                }
            }

            if ( (temp > 2 || temp == 0) && (grid[i][j] == 'X') ) {
                count++;

                // mark (i, j) and neighbors as visited
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (k >= 0 && k < rows && l >= 0 && l < cols && grid[k][l] == 'X') {
                            grid[k][l] = '.';
                        }
                    }
                }
            }

            for (auto &row : grid) {
                for (char &cell : row) {
                    cout << cell << " ";
                }
                cout << endl;
            }

            cout << endl;
            cout << endl;

            temp = 0;
        }
    }

    return count;
}