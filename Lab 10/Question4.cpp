// Pointer array, Question 4

#include <iostream>

using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};

    
    int *ptr = arr;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << "Element " << i << " is: " << *ptr << endl;
        ptr++;
    }

    return 0;
}