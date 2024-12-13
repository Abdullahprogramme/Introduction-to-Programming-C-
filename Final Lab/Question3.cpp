#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> alphaNumeric(vector<string> strings);

int main() {
    vector<string> strings = {"Red", "Blue2", "Green3", "Yellow"};
    vector<string> result = alphaNumeric(strings);

    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}

vector<string> alphaNumeric(vector<string> strings) {
    vector<string> result;
    bool isNum = false, isAlpha = false;

    for (string s : strings) {
        for (char c : s) {
            if (isdigit(c)) {
                isNum = true;
            } else if (isalpha(c)) {
                isAlpha = true;
            }
        }

        if (isNum && isAlpha) {
            result.push_back(s);
        }

        isNum = false;
        isAlpha = false;
    }

    return result;
}
