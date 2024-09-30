// bubble sort

#include <iostream>
#include <array>

using namespace std;

void bubble_sort(int *arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    std::array<int, 10> arr = {3, 8, 2, 5, 7, 4, 9, 6, 10, 19};
    bubble_sort(arr.data(), arr.size());

    // print the sorted array
    for(int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}