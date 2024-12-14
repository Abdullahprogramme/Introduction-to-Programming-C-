#include <iostream>
#include <string>

using namespace std;

// Recursive function to remove duplicates from a string
string removeDuplicates(const string &s);

int main() {
    string s = "AAABBBCCC";
    cout << removeDuplicates(s) << endl; // Expected output: ABC

    s = "AABCD";
    cout << removeDuplicates(s) << endl; // Expected output: ABCD

    s = "ZZYYXX";
    cout << removeDuplicates(s) << endl; // Expected output: ZYX
    
    return 0;
}

// Recursive function to remove duplicates from a string
string removeDuplicates(const string &s) {
    if (s.empty()) {
        return "";
    }

    char c = s[0];
    string rest = removeDuplicates(s.substr(1));

    if (c == rest[0]) {
        return rest;
    }

    return c + rest;
}
