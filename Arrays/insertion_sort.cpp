// insertion sort

#include <iostream>
#include <array>

using namespace std;

void insertion_sort(int *arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::array<int, 10> arr = {3, 8, 2, 5, 7, 4, 9, 6, 10, 19};
    insertion_sort(arr.data(), arr.size());

    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}