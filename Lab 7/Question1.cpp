// Matrix Multiplication

#include <iostream>

using namespace std;

int main() {
    int rows1, cols1;
    cout << "Enter the number of rows and columns of the matrix 1: ";
    cin >> rows1 >> cols1;

    int matrix1[rows1][cols1];
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << "Enter the element at position (" << i << ", " << j << "): ";
            cin >> matrix1[i][j];
        }
    }

    int rows2, cols2;
    cout << "Enter the number of rows and columns of the matrix 2: ";
    cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        cout << "The matrices cannot be multiplied" << endl;
        return 0;
    }

    int matrix2[rows2][cols2];
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << "Enter the element at position (" << i << ", " << j << "): ";
            cin >> matrix2[i][j];
        }
    }

    //printing the matrices
    cout << "\n\nMatrix 1: " << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n\nMatrix 2: " << endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    int result[rows1][cols2];

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // printing the result
    cout << "\n\nThe result of the multiplication is: " << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
