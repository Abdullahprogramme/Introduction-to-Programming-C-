// All four methods are used to set the privileges of the current process.
// Making four functions to set the privileges of the current process.

#include <iostream>

using namespace std;

int f1(int* ptr) {
    cout << "f1" << endl;
    // *ptr = 0;
    return 0;
}

int f2(int* const ptr) {
    cout << "f2" << endl;
    // ptr = nullptr; // Error: assignment of read-only parameter 'ptr'
    *ptr = 0;
    return 0;
}

int f3(const int* ptr) {
    cout << "f3" << endl;
    // *ptr = 0; // Error: assignment of read-only location '* ptr'
    // ptr = nullptr; // Error: assignment of read-only parameter 'ptr'
    return 0;
}

int f4(const int* const ptr) {
    cout << "f4" << endl;
    // ptr = nullptr; // Error: assignment of read-only parameter 'ptr'
    // *ptr = 0; // Error: assignment of read-only location '* ptr'
    return 0;
}

int main() {
    int x = 10;
    int* ptr = &x;
    const int* ptr2 = &x;
    int* const ptr3 = &x;
    const int* const ptr4 = &x;

    f1(ptr); // non-const pointer to non-const data
    f2(ptr3); // const pointer to non-const data
    f3(ptr2); // non-const pointer to const data
    f4(ptr4); // const pointer to const data

    return 0;
}