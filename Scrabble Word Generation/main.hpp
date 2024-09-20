#include <unordered_map>
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

// Function to check if all digits in the combo are unique
bool DigitCheck(const string& combo) {
    set<char> uniqueDigits(combo.begin(), combo.end());
    return uniqueDigits.size() == combo.size();
}

// Function to convert combinations to words using the provided mapping
vector<string> Combo_To_Word(const vector<string>& combos, const unordered_map<char, char>& mapping) {
    set<string> uniqueWords;
    for (const string& combo : combos) {
        string word;
        for (char ch : combo) {
            word += mapping.at(ch);
        }
        uniqueWords.insert(word);
    }
    return vector<string>(uniqueWords.begin(), uniqueWords.end());
}

// Function to generate all unique combinations of a given length
vector<string> Generate_Combinations(int length) {
    set<string> combos;
    string combo(length, '0');
    for (unsigned int i = 1; i <= 7; i++) {
        combo[0] = '0' + i;
        for (unsigned int j = 1; j <= 7; j++) {
            combo[1] = '0' + j;
            if (length > 2) {
                for (unsigned int k = 1; k <= 7; k++) {
                    combo[2] = '0' + k;
                    if (length > 3) {
                        for (unsigned int l = 1; l <= 7; l++) {
                            combo[3] = '0' + l;
                            if (length > 4) {
                                for (unsigned int m = 1; m <= 7; m++) {
                                    combo[4] = '0' + m;
                                    if (length > 5) {
                                        for (unsigned int n = 1; n <= 7; n++) {
                                            combo[5] = '0' + n;
                                            if (length > 6) {
                                                for (unsigned int o = 1; o <= 7; o++) {
                                                    combo[6] = '0' + o;
                                                    if (DigitCheck(combo)) {
                                                        combos.insert(combo);
                                                    }
                                                }
                                            } else if (DigitCheck(combo)) {
                                                combos.insert(combo);
                                            }
                                        }
                                    } else if (DigitCheck(combo)) {
                                        combos.insert(combo);
                                    }
                                }
                            } else if (DigitCheck(combo)) {
                                combos.insert(combo);
                            }
                        }
                    } else if (DigitCheck(combo)) {
                        combos.insert(combo);
                    }
                }
            } else if (DigitCheck(combo)) {
                combos.insert(combo);
            }
        }
    }
    return vector<string>(combos.begin(), combos.end());
}

// Specific functions to generate combinations of different lengths
vector<string> Two_Gen() {
    return Generate_Combinations(2);
}

vector<string> Three_Gen() {
    return Generate_Combinations(3);
}

vector<string> Four_Gen() {
    return Generate_Combinations(4);
}

vector<string> Five_Gen() {
    return Generate_Combinations(5);
}

vector<string> Six_Gen() {
    return Generate_Combinations(6);
}

vector<string> Seven_Gen() {
    return Generate_Combinations(7);
}