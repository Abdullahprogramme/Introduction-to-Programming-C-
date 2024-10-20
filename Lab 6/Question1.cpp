// selection sort

#include <iostream>
#include <array>

using namespace std;

void selection_sort(int *arr, size_t size) {
    int temp;
    for (size_t i = 0; i < size - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }    
}

int main() {
    array<int, 10> arr;

    // taking input from user
    for (unsigned int i{0}; i < arr.size(); i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    selection_sort(arr.data(), arr.size()); // applying the sorting algo

    cout << "Sorted array: \n";
    for (unsigned int i{0}; i < arr.size(); i++) {
        cout << "Value at index " << i + 1 << " is: " << arr[i] << "\n";
    }

    return 0;
}