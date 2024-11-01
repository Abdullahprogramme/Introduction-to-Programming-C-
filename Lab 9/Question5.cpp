// string line to alphanum, Question 5

#include <iostream>
#include <string>

using namespace std;

string str_to_alphanum(string &s);

int main() {
    string s;
    string answer;
    cout << "Enter a line: ";

    string temp;
    while (getline(cin, s) && s != "q") {

        cout << "The alphanums are: ";
        for (int i{0}; i < s.length(); ++i) {
            if (s[i] == ' ') {
                answer = str_to_alphanum(temp);
                if (answer != "0") {
                    cout << answer << " ";
                }
                temp = "";
            } else {
                temp += s[i];
            }
        }

        // Process the last word
        answer = str_to_alphanum(temp);
        if (answer != "0") {
            cout << answer << " ";
        }

        temp = ""; // Reset temp
        cout << endl << "Enter a line: ";
    }

    return 0;
}

string str_to_alphanum(string &s) {
    bool isNum = false;
    bool isAlpha = false;
    string result = "";

    for (int i{0}; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            isNum = true;
            result += s[i];
        } else {
            isAlpha = true;
            result += s[i];
        }
    }

    return (isNum && isAlpha) ? result : "0"; 
}