// selection sort

#include <iostream>
#include <array>

using namespace std;

void selection_sort(int *arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }    
}

int main() {
    std::array<int, 10> arr = {3, 8, 2, 5, 7, 4, 9, 6, 10, 19};
    selection_sort(arr.data(), arr.size());

    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}