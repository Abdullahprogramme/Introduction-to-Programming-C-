#include <iostream>

using namespace std;

// Function declarations with corrected and clear naming
void nonconst_pointer_nonconst_data(int* ptr);         // Non-const pointer to non-const data
void nonconst_pointer_const_data(int const* ptr);      // Non-const pointer to const data
void const_pointer_nonconst_data(int* const ptr);      // Const pointer to non-const data
void const_pointer_const_data(int const* const ptr);   // Const pointer to const data

int main() {
    int x = 10;

    // Creating pointers
    int* ptr1 = &x;           // Non-const pointer to non-const data
    int const* ptr2 = &x;     // Non-const pointer to const data
    int* const ptr3 = &x;     // Const pointer to non-const data
    int const* const ptr4 = &x; // Const pointer to const data

    // Calling functions
    nonconst_pointer_nonconst_data(ptr1);
    nonconst_pointer_const_data(ptr2);
    const_pointer_nonconst_data(ptr3);
    const_pointer_const_data(ptr4);

    return 0;
}

// Function definitions
void nonconst_pointer_nonconst_data(int* ptr) {
    *ptr = 20; // Can modify the data
    int y = 30;
    ptr = &y;  // Can change the pointer to point to another memory location
    cout << "nonconst_pointer_nonconst_data: " << *ptr << endl;
}

void nonconst_pointer_const_data(int const* ptr) {
    // *ptr = 20; // Cannot modify the data (commented out because it's invalid)
    int y = 40;
    ptr = &y;  // Can change the pointer to point to another memory location
    cout << "nonconst_pointer_const_data: " << *ptr << endl;
}

void const_pointer_nonconst_data(int* const ptr) {
    *ptr = 50; // Can modify the data
    // ptr = &x; // Cannot change the pointer to point to another memory location (commented out because it's invalid)
    cout << "const_pointer_nonconst_data: " << *ptr << endl;
}

void const_pointer_const_data(int const* const ptr) {
    // *ptr = 20; // Cannot modify the data (commented out because it's invalid)
    // ptr = &x; // Cannot change the pointer to point to another memory location (commented out because it's invalid)
    cout << "const_pointer_const_data: " << *ptr << endl;
}
