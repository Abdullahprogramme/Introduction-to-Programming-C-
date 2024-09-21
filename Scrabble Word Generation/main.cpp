#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <cmath>
#include "trie.cpp"
#include "main.hpp"

// Define macros to reduce the size of Windows headers and prevent conflicts
#ifndef NOMINMAX
#define NOMINMAX
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOCRYPT
#define NOCRYPT
#endif

#define byte rpc_byte // Avoid conflict with std::byte

#include "termcolor/termcolor.hpp" // Include termcolor for colored output

// Undefine byte to avoid issues in the rest of the code
#undef byte

using namespace std;

int main() {
    Trie trie;
    string filename = "Collins Scrabble Words (2019).txt";
    
    // Read words from the file and insert them into the trie
    readWordsFromFile(filename, trie);

    // Prompt user to enter tiles
    char a, b, c, d, e, f, g;

    while (true) {
        cout << termcolor::bold << termcolor::cyan << "User please enter all the tiles you have in a single line with a single space" << termcolor::reset << endl;
        cin >> a >> b >> c >> d >> e >> f >> g;

        cout << termcolor::bold << termcolor::yellow << "Tile 1" << setw(10) << right << "Tile 2" << setw(10) << right << "Tile 3" << setw(10) << right << "Tile 4" << setw(10) << right << "Tile 5" << setw(10) << right << "Tile 6" << setw(10) << right << "Tile 7" << termcolor::reset << endl;
        cout << setw(10) << left << a << setw(10) << left << b << setw(10) << left << c << setw(10) << left << d << setw(10) << left << e << setw(10) << left << f << setw(10) << left << g << endl;

        cout << termcolor::bold << termcolor::green << "Generating words..." << termcolor::reset << endl;

        // Generate a mapping from numbers to tiles
        unordered_map<char, char> mapping = {
            {'1', a},
            {'2', b},
            {'3', c},
            {'4', d},
            {'5', e},
            {'6', f},
            {'7', g}
        };

        // Generate all possible combinations of 2, 3, 4, 5, 6, and 7 tiles
        vector<string> combos2 = Two_Gen();
        vector<string> combos3 = Three_Gen();
        vector<string> combos4 = Four_Gen();
        vector<string> combos5 = Five_Gen();
        vector<string> combos6 = Six_Gen();
        vector<string> combos7 = Seven_Gen();

        // Convert each combination to a word using the mapping
        vector<string> words2 = Combo_To_Word(combos2, mapping);
        vector<string> words3 = Combo_To_Word(combos3, mapping);
        vector<string> words4 = Combo_To_Word(combos4, mapping);
        vector<string> words5 = Combo_To_Word(combos5, mapping);
        vector<string> words6 = Combo_To_Word(combos6, mapping);
        vector<string> words7 = Combo_To_Word(combos7, mapping);

        // Validate words by checking if they exist in the trie
        vector<string> validWords2, validWords3, validWords4, validWords5, validWords6, validWords7;
        for (string word : words2) {
            if (trie.search(word)) {
                validWords2.push_back(word);
            }
        }

        for (string word : words3) {
            if (trie.search(word)) {
                validWords3.push_back(word);
            }
        }

        for (string word : words4) {
            if (trie.search(word)) {
                validWords4.push_back(word);
            }
        }

        for (string word : words5) {
            if (trie.search(word)) {
                validWords5.push_back(word);
            }
        }

        for (string word : words6) {
            if (trie.search(word)) {
                validWords6.push_back(word);
            }
        }

        for (string word : words7) {
            if (trie.search(word)) {
                validWords7.push_back(word);
            }
        }

        // Output valid words to respective files
        ofstream file2("2.txt");
        for (string word : validWords2) {
            file2 << word << endl;
        }
        file2.close();

        ofstream file3("3.txt");
        for (string word : validWords3) {
            file3 << word << endl;
        }
        file3.close();

        ofstream file4("4.txt");
        for (string word : validWords4) {
            file4 << word << endl;
        }
        file4.close();

        ofstream file5("5.txt");
        for (string word : validWords5) {
            file5 << word << endl;
        }
        file5.close();

        ofstream file6("6.txt");
        for (string word : validWords6) {
            file6 << word << endl;
        }
        file6.close();

        ofstream file7("7.txt");
        for (string word : validWords7) {
            file7 << word << endl;
        }
        file7.close();

        cout << termcolor::bold << termcolor::green << "Words generated and validated successfully!" << termcolor::reset << endl;
        
        // Summary of valid words in each category
        cout << termcolor::bold << termcolor::cyan << "Summary of valid words:" << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::magenta << setw(15) << left << "Category" << setw(10) << right << "Total" << setw(10) << right << "Unique" << setw(10) << right << "Valid" << setw(10) << right << "Invalid" << endl;
        cout << termcolor::red << setw(15) << left << "2-letter words:" << setw(10) << right << pow(7, 2) << setw(10) << right << words2.size() << setw(10) << right << validWords2.size() << setw(10) << right << (words2.size() - validWords2.size()) << endl;
        cout << termcolor::red << setw(15) << left << "3-letter words:" << setw(10) << right << pow(7, 3) << setw(10) << right << words3.size() << setw(10) << right << validWords3.size() << setw(10) << right << (words3.size() - validWords3.size()) << endl;
        cout << termcolor::red << setw(15) << left << "4-letter words:" << setw(10) << right << pow(7, 4) << setw(10) << right << words4.size() << setw(10) << right << validWords4.size() << setw(10) << right << (words4.size() - validWords4.size()) << endl;
        cout << termcolor::red << setw(15) << left << "5-letter words:" << setw(10) << right << pow(7, 5) << setw(10) << right << words5.size() << setw(10) << right << validWords5.size() << setw(10) << right << (words5.size() - validWords5.size()) << endl;
        cout << termcolor::red << setw(15) << left << "6-letter words:" << setw(10) << right << pow(7, 6) << setw(10) << right << words6.size() << setw(10) << right << validWords6.size() << setw(10) << right << (words6.size() - validWords6.size()) << endl;
        cout << termcolor::red << setw(15) << left << "7-letter words:" << setw(10) << right << pow(7, 7) << setw(10) << right << words7.size() << setw(10) << right << validWords7.size() << setw(10) << right << (words7.size() - validWords7.size()) << endl;

        // Ask user if they want to continue
        cout << termcolor::bold << termcolor::cyan << "Do you want to continue? (y/n)" << termcolor::reset << endl;
        char choice;
        cin >> choice;
        if (choice == 'n') {
            break;
        }
    }
    return 0;
}
