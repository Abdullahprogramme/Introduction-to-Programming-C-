#include <iostream>
#include <string>

using namespace std;

int count(int arr[], int size, int element);

int main () {
    int element;
    int arr[] = {1, 2, 2, 2, 3, 4, 3, 2, 1, 1, 1, 6, 9, 9, 3, 6, 2, 9, 6, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter the element you want to count: ";
    cin >> element;

    cout << "The element " << element << " is repeated " << count(arr, size, element) << " times." << endl;

    return 0;
}

int count(int arr[], int size, int element) {
    if (size == 0) {
        return 0;
    }
    if (arr[size - 1] == element) {
        return 1 + count(arr, size - 1, element);
    }
    return count(arr, size - 1, element);
}
