// String to Integer, Question 2

#include <iostream>
#include <string>

using namespace std;

int str_to_int(string &s);

int main() {
    string s;
    int answer;
    cout << "Enter a number: ";

    while (cin >> s && s != "q") {
        answer = str_to_int(s);
        if (answer != 0) {
            cout << "The number is: " << answer << endl;
        }
        cout << "Enter a number: ";
    }
    

    return 0;
}

int str_to_int(string &s) {
    bool isNeg = false;
    int i = 0;

    if (s[0] == '-') {
        isNeg = true;
        i = 1;
    }

    int number = 0;
    for (; i < s.length(); ++i) {
        if (s[i] < '0' || s[i] > '9') {
            cout << "Invalid input." << endl;
            return 0;
        }
        number = number * 10 + s[i] - '0';
    }

    return isNeg ? -number : number;
}