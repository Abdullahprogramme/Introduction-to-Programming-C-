#include <iostream>

using namespace std;

int main() {
    // Types of pointers:

    // 1. null pointer -> explanation: pointer that doesn't point to any memory location.
    int* ptr = nullptr;
    cout << "ptr: " << ptr << endl;

    // 2. void pointer -> explanation: pointer that can point to any data type.
    int a = 10;
    char b = 'a';
    void* ptr1 = &a;
    cout << "ptr1: " << *static_cast<int*>(ptr1) << endl;
    ptr1 = &b;
    cout << "ptr1: " << *static_cast<char*>(ptr1) << endl;

    // 3. wild pointer -> explanation: pointer that is not initialized.
    int* ptr2;
    cout << "ptr2: " << ptr2 << endl;

    // 4. dangling pointer -> explanation: pointer that points to a memory location that has been deallocated.
    int* ptr3 = new int(10);
    cout << "ptr3: " << *ptr3 << endl;
    delete ptr3; // After this, ptr3 becomes a dangling pointer.
    // Accessing ptr3 after deletion can lead to undefined behavior.
    cout << "ptr3: " << *ptr3 << endl; // Uncommenting this line will cause undefined behavior.
    
    // Concepts about mutabilty and non-mutability of anything in C++:

    // Mutable -> explanation: can be changed.
    int x = 10;
    int* ptr4 = &x;
    *ptr4 = 20;
    cout << "x: " << x << endl;

    // Non-mutable -> explanation: cannot be changed.
    const int y = 10;
    // int* ptr5 = &y; // Uncommenting this line will cause an error.
    // *ptr5 = 20; // Uncommenting this line will cause an error.
    cout << "y: " << y << endl;
    
    return 0;
}