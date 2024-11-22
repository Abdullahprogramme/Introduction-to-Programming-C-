// Words / sentences/articles(a, an, the) / spaces checker and word replacer, Question 3

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

void count_stats(const string &str, int option);

int main() {
    string text;
    int option;

    cout << "Enter a text: ";
    cin.ignore();
    getline(cin, text);

    cout << "Enter an option: \n"
         << "1. Count the number of words\n"
         << "2. Count the number of sentences\n"
         << "3. Count the number of articles\n"
         << "4. Count the number of spaces\n"
         << "5. Replace some word\n"; 
    cin >> option;

    count_stats(text, option);
    return 0;
}

void count_stats(const string &str, int option) {
    if (option < 1 || option > 5) {
        cout << "Invalid option";
        return;
    }

    string text = str;
    transform(text.begin(), text.end(), text.begin(), ::tolower); // Normalize case once

    switch (option) {
        case 1: {
            // Count words using `std::count_if`
            int word_count = 0;
            bool in_word = false;

            word_count = count_if(text.begin(), text.end(), [&](char c) {
                if (isalnum(c)) {
                    in_word = true;
                    return false;
                } else if (in_word) {
                    in_word = false;
                    return true;
                }
                return false;
            });

            if (in_word) ++word_count; // Account for the last word
            cout << "Number of words: " << word_count;
            break;
        }
        case 2: {
            // Count sentences using `std::count_if`
            int sentence_count = count_if(text.begin(), text.end(), [](char c) {
                return c == '.' || c == '?' || c == '!';
            });
            cout << "Number of sentences: " << sentence_count;
            break;
        }
        case 3: {
            // Tokenize and count articles ('a', 'an', 'the')
            vector<string> articles = {"a", "an", "the"};
            int article_count = 0;
            stringstream ss(text);
            string word;

            while (ss >> word) {
                // Remove trailing punctuation (e.g., 'an.' -> 'an')
                while (!word.empty() && std::ispunct(word.back())) {
                    word.pop_back();
                }
                
                if (find(articles.begin(), articles.end(), word) != articles.end()) {
                    ++article_count;
                }
            }
            cout << "Number of articles: " << article_count;
            break;
        }
        case 4: {
            // Count spaces using `std::count`
            int space_count = count(text.begin(), text.end(), ' ');
            cout << "Number of spaces: " << space_count;
            break;
        }
        case 5: {
            // Replace words in the text
            string replacer, replacement;
            cout << "Enter the word to be replaced: ";
            cin >> replacer;
            cout << "Enter the replacement: ";
            cin >> replacement;

            size_t pos = text.find(replacer);
            while (pos != string::npos) {
                // Check word boundaries
                bool valid_start = (pos == 0 || !isalnum(text[pos - 1]));
                bool valid_end = (pos + replacer.size() == text.size() || !isalnum(text[pos + replacer.size()]));
                
                if (valid_start && valid_end) {
                    text.replace(pos, replacer.size(), replacement);
                }
                pos = text.find(replacer, pos + replacement.size());
            }
            cout << "Replaced text: " << text;
            break;
        }
    }
}
