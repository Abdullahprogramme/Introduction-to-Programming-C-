// Int swap. Question 5

#include <iostream>

using namespace std;

void swap(int* a, int* b);

int main() {
    cout << "Enter two integers: ";
    int a, b;
    cin >> a >> b;

    swap(&a, &b);

    // outputting them after swapping
    cout << "After swapping, a is: " << a << " and b is: " << b << endl;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}