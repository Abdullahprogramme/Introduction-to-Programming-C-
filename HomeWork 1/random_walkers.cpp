// Abdullah Tariq, 29123
// Description: This program simulates a random walker on a 2D grid.
// The walker starts at the center of the grid and moves in a random direction.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int max_steps;
    int trials;
    int total_distance = 0;

    cout << "Enter the number of steps and number of trials: ";
    cin >> max_steps >> trials;

    for (int i = 0; i < trials; i++) {

        int x = 0, y = 0; // starting coordinates
        
        // cout << "(" << x << ", " << y << ")" << endl;
        for (unsigned int step = 0; step < max_steps - 1; step++) {
            int direction = rand() % 4; // 0: up, 1: right, 2: down, 3: left, consider it as a hashmap

            switch (direction) {
                case 0: // 0 means up so increase y by 1
                    y++;
                    break;
                case 1: // 1 means right so increase x by 1
                    x++;
                    break;
                case 2: // 2 means down so decrease y by 1
                    y--;
                    break;
                case 3: // 3 means left so decrease x by 1
                    x--;
                    break;
            }

            // cout << '(' << x << ", " << y << ")" << endl;
        }

        // squaring the final distance covered (euclidean distance)
        int distance = x * x + y * y;
        // cout << "Squared distance: " << distance << endl;

        total_distance += distance;
    }

    cout << "Mean squared distance = " << double(total_distance) / trials << endl;
}