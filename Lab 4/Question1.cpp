// GCD between the two positive numbers

#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    while (num1 <= 0) {
        cout << "Please enter a positive number: ";
        cin >> num1;
    }

    cout << "Enter second number: ";
    cin >> num2;
    while (num2 <= 0) {
        cout << "Please enter a positive number: ";
        cin >> num2;
    }
    
    while (num1 != num2) {
        if (num1 > num2) {
            num1 -= num2;
        } else {
            num2 -= num1;
        }
    }

    cout << "The GCD of the two numbers is " << num1 << endl;
}