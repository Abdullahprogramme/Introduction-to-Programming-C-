// Odd / Even remover using array

#include <iostream>
#include <array>
#include <cmath>

using namespace std;

void remove_odd_or_even(long long val) {
    const size_t digits = 50; // assuming the number can be of 50 digits
    array<int, digits> arr = {0}; // array to store the digits

    int i = 0;
    while (val > 0) { // storing the digits in array
        arr[i] = val % 10;
        val /= 10;
        i++;
    }

    string choice;
    cout << "Enter 'even' to output only even numbers or 'odd' to output only odd numbers: ";
    cin >> choice;


    int final = 0; // var to store the final number, where it will be stored backwards ex: 1234 -> 4321
    if (choice == "even") {
        cout << "After removing odd numbers: ";
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] % 2 == 0) {
                final = final * 10 + arr[j];
            }
        }
    } else if (choice == "odd") {
        cout << "After removing even numbers: ";
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] % 2 != 0) {
                final = final * 10 + arr[j];
            }
        }
    } else {
        cout << "Invalid choice!";
    }

    cout << final << endl;

}

int main() {
    long long val; // since number can be anything
    
    // taking input from user
    cout << "Enter the integer number: ";
    cin >> val;

    remove_odd_or_even(val); // applying the remover algo

    return 0;
}