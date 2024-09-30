// Arrays
#include <iostream>
#include <array>
#include <vector>

// built in arrays are fixed size
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 10 elements

// some functions on this built in array
void built_in_array() {
    // size of the array
    std::cout << "Size of the array: " << sizeof(arr) / sizeof(arr[0]) << std::endl;

    // accessing elements
    std::cout << "First element: " << arr[0] << std::endl;
    std::cout << "Last element: " << arr[9] << std::endl;

    // changing elements
    arr[0] = 100;
    std::cout << "First element after change: " << arr[0] << std::endl;

    // iterating over the array
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // some more functions which can be implemented on this array

    // std::begin and std::end
    for (int *i = std::begin(arr); i != std::end(arr); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    // std::fill
    std::fill(std::begin(arr), std::end(arr), 0);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        std::cout << arr[i] << " ";
    }
}

// standard library array
void std_array() {
    std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // size of the array
    std::cout << "Size of the array: " << arr.size() << std::endl;

    // accessing elements
    std::cout << "First element: " << arr[0] << std::endl;
    std::cout << "Last element: " << arr[9] << std::endl;

    // changing elements
    arr[0] = 100;
    std::cout << "First element after change: " << arr[0] << std::endl;

    // iterating over the array
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // some more functions which can be implemented on this array

    // std::begin and std::end
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // std::fill
    std::fill(arr.begin(), arr.end(), 0);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
}

void std_vectors() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // size of the vector
    std::cout << "Size of the vector: " << vec.size() << std::endl;

    // accessing elements
    std::cout << "First element: " << vec[0] << std::endl;
    std::cout << "Last element: " << vec[9] << std::endl;

    // changing elements
    vec[0] = 100;
    std::cout << "First element after change: " << vec[0] << std::endl;

    // iterating over the vector
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // some more functions which can be implemented on this vector

    // std::begin and std::end
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // std::fill
    std::fill(vec.begin(), vec.end(), 0);

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);

    vec.pop_back();
    vec.pop_back();

    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}

void min_checker(int *arr, size_t size) {
    int min_index = 0;
    int min_value = arr[0]; // Initialize with the first element

    for (size_t i = 1; i < size; i++) { // Start from the second element
        if (arr[i] < min_value) {
            min_value = arr[i];
            min_index = i;
        }
    }
    std::cout << "Min value: " << min_value << " at index: " << min_index << std::endl;
}

void for_each_loop() {
    std::array<int, 10> arr = {3, 8, 2, 5, 7, 4, 9, 6, 10, 19};
    int min = arr[0];
    for (int i : arr) {
        std::cout << i << " ";
        if (min > i) {
            min = i;
        }
    }
    std::cout << std::endl << "Min value: " << min << std::endl;

    // referencing and then updating them
    for (int &i : arr) {
        i *= 2;
    }
    std::cout << "After updating: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
}

void bubble_sort(int *arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    // print the sorted array
    for(size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    built_in_array();
    std::cout << std::endl << "----------------" << std::endl;
    std_array();
    std::cout << std::endl << "----------------" << std::endl;
    std_vectors();

    // std::vector<int> vec[10] = {
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9},
    //     {10, 11, 12},
    //     {13, 14, 15},
    //     {16, 17, 18},
    //     {19, 20, 21},
    //     {22, 23, 24},
    //     {25, 26, 27},
    //     {28, 29, 30}
    // };
    // for (int i = 0; i < 10; i++) {
    //     std::cout << "Vector " << i + 1 << ": ";
    //     for (int j = 0; j < vec[i].size(); j++) {
    //         std::cout << vec[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << std::endl << "----------------" << std::endl;
    std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    min_checker(arr.data(), arr.size());

    std::cout << std::endl << "----------------" << std::endl;
    for_each_loop();

    std::cout << std::endl << "----------------" << std::endl;
    arr = {1, 3, 91, 3, 82, 94, 218, 91, 2, 9};
    bubble_sort(arr.data(), arr.size());
    return 0;
}