// merge sort

#include <iostream>
#include <array>

using namespace std;

void merge(int *arr, size_t low, size_t mid, size_t high) {
    size_t n1 = mid - low + 1;
    size_t n2 = high - mid;

    int L[n1], R[n2];

    for (size_t i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }

    for (size_t j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    size_t i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, size_t low, size_t high) {
    if (low < high) {
        size_t mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    std::array<int, 10> arr = {3, 8, 2, 5, 7, 4, 9, 6, 10, 19};
    merge_sort(arr.data(), 0, arr.size() - 1);

    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}