// Find largest word in string, Question 4

#include <iostream>
#include <string>

using namespace std;

string largest_word(string &str);

int main() {
    string text;
    cout << "Enter a text: ";
    getline(cin, text);

    cout << "Largest word: " << largest_word(text);
}

string largest_word(string &str) {
    string word;
    string largest;
    for (char &c : str) {
        // also checking character: hyphen
        if (isalpha(c) || c == '-') {
            word += c;
        } else {
            if (word.length() > largest.length()) {
                largest = word;
            }
            word.clear();
        }
    }
    return largest;
}