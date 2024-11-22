// Sum of reciprocals of the first n natural numbers, Question 3

#include <iostream>
using namespace std;

double sumTo(int n);

int main() {
    int n;
    cout << "Enter a number 'n' >= 0: ";
    cin >> n;

    cout << "Sum of reciprocals of the first " << n << " natural numbers is " << sumTo(n) << endl;
    return 0;
}

double sumTo(int n) {
    if (n == 0) return 0;
    return 1.0/n + sumTo(n - 1);
}