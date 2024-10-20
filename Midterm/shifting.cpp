#include <iostream>

using namespace std;

int main() {

    // wrong way to shift elements one position to the right
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        arr[i] = arr[(i + 1) % size];
    }
    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;

    // correct way to shift elements one position to the right
    int arr2[5] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int temp = arr2[size2 - 1];
    for (int i = size2 - 1; i > 0; i--) {
        arr2[i] = arr2[i - 1];
    }
    arr2[0] = temp;
    for (int i : arr2) {
        cout << i << " ";
    }
}