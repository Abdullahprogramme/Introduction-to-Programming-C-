// Character check, Question 3

#include <iostream>
using namespace std;

int charactercheck (string line, char c);

int main() {
    string line;
    char c;

    cout << "Enter a line of text: ";
    getline(cin, line);

    cout << "Enter a character: ";
    cin >> c;

    cout << "Number of " << c << "\'s in \"" << line << "\" is " << charactercheck(line, c) << endl;
}

int charactercheck (string line, char c) {
    if (line.length() == 0) {
        return 0;
    }
    
    int count = 0;
    for (char i : line) {
        if (i == c) {
            count++;
        }
    }

    return count;
}