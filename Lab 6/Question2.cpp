// odd digit remover

#include <iostream>
#include <array>

using namespace std;

void Odd_digit_remover(int val) {
    int answer = 0;
    int multiplier = 1;

    while (val > 0) {
        int digit = val % 10;
        if (digit % 2 == 0) {
            answer = answer + digit * multiplier;
            multiplier *= 10;
        }
        val = val / 10;
    }

    int newNumber = 0;

    multiplier = 1;
    while (answer > 0) {
        int digit = answer % 10;
        newNumber = newNumber + digit * multiplier;
        multiplier *= 10;
        answer = answer / 10;
    }
    
    cout << "Number after removing odd digits: " << newNumber << endl;
}

int main() {
    int val;
    
    // taking input from user
    cout << "Enter the integer number: ";
    cin >> val;

    Odd_digit_remover(val); // applying the remover algo

    return 0;
}