// Greater than, Question 6

#include <iostream>

using namespace std;

int countGreaterThan(int *arr, int size, int threshold);

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int threshold;

    cout << "Enter a threshold: ";
    cin >> threshold;

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Number of elements greater than " << threshold << " is: " << countGreaterThan(arr, size, threshold) << endl;
}

int countGreaterThan(int *arr, int size, int threshold) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (*(arr + i) > threshold) {
            count++;
        }
    }

    return count;
}