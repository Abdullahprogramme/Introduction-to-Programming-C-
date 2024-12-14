#include <iostream>
#include <string>

using namespace std;

// RLE (Run-Length Encoding) is a simple form of data compression where runs of data are stored as a single data value and count.
// For example, the string "AAABBBCCC" can be compressed to "A3B3C3".

// Function to decode a RLE string
string decodeRLE(const string &s);

int main() {
    string s = "A3B3C3";
    cout << decodeRLE(s) << endl; // Expected output: AAABBBCCC

    s = "A2B1C1D1";
    cout << decodeRLE(s) << endl; // Expected output: AABCD

    s = "Z1Y1X1";
    cout << decodeRLE(s) << endl; // Expected output: ZYX

    return 0;
}

string decodeRLE(const string &s) {
    string result;
    for (unsigned int i = 0; i < s.size(); i += 2) {
        char c = s[i];
        int count = s[i + 1] - '0';
        result.append(count, c);
    }
    return result;
}