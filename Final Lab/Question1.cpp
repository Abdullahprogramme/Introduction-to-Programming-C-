#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Directions for movement: up, down, left, right
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// Function to find the largest increasing subsequence without duplicates and display it and its length
void largest_increasing_subsequence(array<array<int, 3>, 3> arr);

void dfs(const array<array<int, 3>, 3> &arr, int x, int y, set<int> &visited, vector<int> &current, vector<int> &best) {
    // Add current element to the path
    visited.insert(arr[x][y]);
    current.push_back(arr[x][y]);

    // Check if the current path is better
    if (current.size() > best.size()) {
        best = current;
    }

    // Explore neighbors
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // Check bounds and increasing condition
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && arr[nx][ny] > arr[x][y] && visited.find(arr[nx][ny]) == visited.end()) {
            dfs(arr, nx, ny, visited, current, best);
        }
    }

    // Backtrack
    visited.erase(arr[x][y]);
    current.pop_back();
}

int main() {
    array<array<int, 3>, 3> arr = {
        {
            {4, 5, 3},
            {3, 4, 2},
            {2, 1, 1}
        }
    }; // Expected largest increasing subsequence: 1 2 3 4 5

    array<array<int, 3>, 3> arr2 = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }
    }; // Expected largest increasing subsequence: 1 4 7 8 9

    array<array<int, 3>, 3> arr3 = {
        {
            {5, 9, 3},
            {4, 8, 2},
            {3, 7, 1}
        }
    }; // Expected largest increasing subsequence: 1 7 8 9

    largest_increasing_subsequence(arr);
    largest_increasing_subsequence(arr2);
    largest_increasing_subsequence(arr3);

    return 0;
}

void largest_increasing_subsequence(array<array<int, 3>, 3> arr) {
    vector<int> best; // To store the largest increasing subsequence

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            set<int> visited; // To track visited elements and avoid duplicates
            vector<int> current; // Current path

            dfs(arr, i, j, visited, current, best);
        }
    }

    // Display the result
    for (int num : best) {
        cout << num << " ";
    }

    cout << endl << "Length: " << best.size() << endl;
}
