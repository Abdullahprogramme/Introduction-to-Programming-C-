#include <iostream>

using namespace std;

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(arr[0]) / sizeof(arr[0][0]);

    // smake pattern method 1
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                cout << arr[i][j] << " ";
            }
        }
    }

    cout << endl;

    // snake pattern method 2
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) {
                cout << arr[i][j] << " ";
            } else {
                cout << arr[i][n - j - 1] << " ";
            }
        }
    }

    return 0;
}