// Fibonacci series using recursion, Question 2

#include <iostream>
using namespace std;

int fibonacci(int n);

int main() {
    int n;
    cout << "Enter a number 'n' >= 0: ";
    cin >> n;

    cout << "Fibonacci series up to position " << n << " is: ";

    for(unsigned int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}