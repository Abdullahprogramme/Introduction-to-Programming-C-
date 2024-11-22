// Anagram checking where second string may have spaces, Question 2

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isAnagram(string &str1, string &str2);

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    (isAnagram(str1, str2)) ? cout << "The strings are anagrams" : cout << "The strings are not anagrams";
}

bool isAnagram(string &str1, string &str2) {
    unordered_map<char, int> freq1, freq2;

    // counting the frequency of each character in the first string
    for (char c : str1) {
        if (isalpha(c)) {
            freq1[tolower(c)]++;
        }
    }

    // counting the frequency of each character in the second string
    for (char c : str2) {
        if (isalpha(c)) {
            freq2[tolower(c)]++;
        }
    }

    // checking if the frequency of each character in the first string is the same as the frequency of each character in the second string
    return freq1 == freq2;
    
}