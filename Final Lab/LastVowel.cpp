#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to find the last vowel in a word in a string and remove it
string removeLastVowel(const string &sentence);

int main() {
    string sentence = "Hello, world!";
    cout << removeLastVowel(sentence) << endl; // Expected output: Hell, wrld!
    
    sentence = "The quick brown fox jumps over the lazy dog.";
    cout << removeLastVowel(sentence) << endl; // Expected output: Th quck brwn fx jmps ovr th lzy dg.
    
    sentence = "Programming is fun!";
    cout << removeLastVowel(sentence) << endl; // Expected output: Programmin s fn!

    sentence = "Love is a serious mental disease.";
    cout << removeLastVowel(sentence) << endl; // Expected output: Lov s a serius mentl diseas.
    
    return 0;
}

string removeLastVowel(const string &sentence) {
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    string word;

    stringstream ss(sentence);
    vector<string> result;

    while (getline(ss, word, ' ')) {
        for (int i = word.size() - 1; i >= 0; i--) {
            if (find(vowels.begin(), vowels.end(), tolower(word[i])) != vowels.end()) {
                word.erase(i, 1);
                break;
            }
        }
        if (word != "") {
            result.push_back(word);
        }
    }

    string final;
    for (const string &w : result) {
        final += w + " ";
    }

    return final;
}