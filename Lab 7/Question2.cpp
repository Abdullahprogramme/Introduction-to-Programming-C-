// bubble sort

#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size] = {0};

    // taking input from the user
    for (int i = 0; i < size; i++) {
        cout << "Enter the element at position " << i << ": ";
        cin >> arr[i];
    }

    int temp;
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // print the sorted array
    for(int i : arr) {
        cout << i << " ";
    }

    return 0;
}