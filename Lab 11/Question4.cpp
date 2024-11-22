// Remove 'x' from string, Question 4

#include <iostream>
using namespace std;

string removeX(string s);

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "String after removing 'x' is: " << removeX(s) << endl;
    return 0;
}

string removeX(string s) {
    if (s.length() == 0) return "";
    if (s[0] == 'x') return removeX(s.substr(1));
    return s[0] + removeX(s.substr(1));
}