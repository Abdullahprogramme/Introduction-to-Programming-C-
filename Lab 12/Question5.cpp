// checking subsequence, Question 5

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isSubsequence(string &str1, string &sub);

int main() {
    string str1, sub;
    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, sub);

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
    
    (isSubsequence(str1, sub)) ? cout << 1 : cout << 0;
}

bool isSubsequence(string &str1, string &sub) {
    int i = 0;
    int j = 0;
    while (i < str1.length() && j < sub.length()) {
        if (str1[i] == sub[j]) {
            j++;
        }
        i++;
    }
    return j == sub.length();
}