#include <iostream>
#include <array>

// Partition function for quick sort
size_t partition(int *arr, size_t low, size_t high) {
    int pivot = arr[high];
    size_t i = low; // Initialize i to low

    for (size_t j = low; j < high; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}

// Quick sort function
void quick_sort(int *arr, size_t low, size_t high) {
    if (low < high) {
        size_t pi = partition(arr, low, high);
        if (pi > 0) { // Ensure no underflow
            quick_sort(arr, low, pi - 1);
        }
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    std::array<int, 10> arr = {3, 8, 2, 5, 7, 4, 9, 6, 10, 19};
    quick_sort(arr.data(), 0, arr.size() - 1);

    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}