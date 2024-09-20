// Palindrome number

#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a 4-digit number: ";
    cin >> number;
    int temp = number;
    int reverse = 0;
    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    if (reverse == number) {
        cout << "The number is a palindrome." << endl;
    } else {
        cout << "The number is not a palindrome." << endl;
    }
    return 0;
}