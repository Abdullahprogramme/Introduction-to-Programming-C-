#include <iostream>
#include <string>

using namespace std;

// Recursive Function to find the interleaving string of two strings
void interleavingString(const string &s1, const string &s2, const string &result);

int main() {
    string s1 = "AB";
    string s2 = "CD";
    interleavingString(s1, s2, "");
    return 0;
}

void interleavingString(const string &s1, const string &s2, const string &result) {
    if (s1.empty() && s2.empty()) {
        cout << result << endl;
        return;
    }

    if (!s1.empty()) {
        interleavingString(s1.substr(1), s2, result + s1[0]);
    }

    if (!s2.empty()) {
        interleavingString(s1, s2.substr(1), result + s2[0]);
    }
}