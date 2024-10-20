// merging arrays

#include <iostream>

using namespace std;

int main() {
    int size1, size2;
    cout << "Enter the size of the first array: ";
    cin >> size1;

    cout << "Enter the size of the second array: ";
    cin >> size2;

    // declaring arrays
    int arr1[size1], arr2[size2], result[size1 + size2] = {0};

    for (int i = 0; i < size1 + size2; i++) {
        result[i] = 0;
    }

    // taking input from the user
    cout << "\n\nEnter the elements of the first array \n";
    for (int i = 0; i < size1; i++) {
        cout << "Enter the element at position " << i << ": ";
        cin >> arr1[i];
    }

    cout << "\nEnter the elements of the second array \n";
    for (int i = 0; i < size2; i++) {
        cout << "Enter the element at position " << i << ": ";
        cin >> arr2[i];
    }


    // merging the arrays
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    // if there are elements left in the first array
    while (i < size1) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    // if there are elements left in the second array
    while (j < size2) {
        result[k] = arr2[j];
        j++;
        k++;
    }

    // printing the merged array
    cout << "The merged array is: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << result[i] << " ";
    }
}