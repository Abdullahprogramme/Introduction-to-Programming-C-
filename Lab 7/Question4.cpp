// Insertion in an array

#include <iostream>

using namespace std;

int main() {
    int elements, insertion_val;
    cout << "Enter the number of elements in the array: ";
    cin >> elements;

    if (elements > 20) {
        cout << "The number of elements cannot exceed 20" << endl;
        return 0;
    } else if (elements == 20) {
        cout << "Insertion not possible" << endl;
        return 0;
    }

    int arr[20] = {0};

    for (size_t i{0}; i < elements; i++) {
        cout << "Enter the element at position " << i << ": ";
        cin >> arr[i];
    }

    for (int i : arr) {
        cout << i << " ";
    }

    cout << "\nEnter a element to be inserted in the array: ";
    cin >> insertion_val;


    int temp;
    for (size_t i{0}; i < sizeof(arr) / sizeof(arr[0]); i++) {
        if (arr[i] > insertion_val) { // found the position to insert the element
            cout << "The position to insert the element is: " << i << endl;
            for (size_t j{i}; j < elements+1; j++) {
                // shifting the elements to the right
                temp = arr[j];
                arr[j] = insertion_val;
                insertion_val = temp;
            }
            break;
        }
    }

    cout << "The array after insertion is: ";
    for (int i : arr) {
        cout << i << " ";
    }

}