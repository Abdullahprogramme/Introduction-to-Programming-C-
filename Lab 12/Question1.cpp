// Password checker, Question 1

#include <iostream>
#include <string>

using namespace std;

bool isValid(string &str);

int main() {
    string password;
    cout << "Enter a password: ";
    cin >> password;

    (isValid(password)) ? cout << "Valid password" : cout << "Invalid password";
}

bool isValid(string &str) {
    int num_char = str.length();
    int num_digit = 0;
    int num_lett = 0;

    // counting the number of letters and digits
    for (int i = 0; i < num_char; i++) {
        if (isalpha(str[i])) {
            num_lett++;
        } else if (isdigit(str[i])) {
            num_digit++;
        } else {
            return false;
        }
    }

    // checking if there are at least 1 letter and 2 digits
    return (num_lett >= 1 && num_digit >= 2 && num_char >= 10);
}