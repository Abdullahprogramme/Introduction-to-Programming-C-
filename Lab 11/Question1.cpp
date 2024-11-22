// Factorial function, Question 1

#include <iostream>
using namespace std;

int factorial(int n);

int main() {
    int n;
    cout << "Enter a number 'n' >= 0: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}