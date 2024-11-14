// All four methods are used to set the privileges of the current process.
// Making four functions to set the privileges of the current process.

#include <iostream>

using namespace std;

void nonconst_pointer_nonconst_data(int* ptr);
void const_pointer_nonconst_data(int const* ptr);
void nonconst_pointer_const_data(int* const ptr);
void const_pointer_const_data(int const* const ptr);

int main() {
    int x = 10;

    // creating pointers
    int* ptr1 = &x;
    int const* ptr2 = &x;
    int* const ptr3 = &x;
    int const* const ptr4 = &x;

    // calling functions
    nonconst_pointer_nonconst_data(ptr1);
    const_pointer_nonconst_data(ptr2);
    nonconst_pointer_const_data(ptr3);
    const_pointer_const_data(ptr4);

    return 0;
}

void nonconst_pointer_nonconst_data(int* ptr) {
    *ptr = 20; // can change the data
    int y = 20;
    ptr = &y; // can change the pointer to point to another memory location
    cout << "nonconst_pointer_nonconst_data: " << *ptr << endl; // can read the data
}

void const_pointer_nonconst_data(int const* ptr) {
    // *ptr = 20; // cannot change the data
    int y = 20;
    ptr = &y; // can change the pointer to point to another memory location
    cout << "const_pointer_nonconst_data: " << *ptr << endl; // can read the data
}

void nonconst_pointer_const_data(int* const ptr) {
    *ptr = 20; // can change the data
    // int y = 20;
    // ptr = &y; // cannot change the pointer to point to another memory location
    cout << "nonconst_pointer_const_data: " << *ptr << endl; // can read the data
}

void const_pointer_const_data(int const* const ptr) {
    // *ptr = 20; // cannot change the data
    // int y = 20;
    // ptr = &y; // cannot change the pointer to point to another memory location
    cout << "const_pointer_const_data: " << *ptr << endl; // can read the data
}
