#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
};

void readWordsFromFile(const string& filename, Trie& trie) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    string word;
    while (file >> word) {
        for (char& ch : word) {
            ch = tolower(ch);
        }
        trie.insert(word);
        cout << "Inserterd " << word << endl;
    }

    file.close();
}

// int main() {
//     Trie trie;
//     string filename = "Collins Scrabble Words (2019).txt";
//     readWordsFromFile(filename, trie);

//     cout << trie.search("abandonwares") << endl;
//     cout << trie.search("abator") << endl;
//     cout << trie.search("megahit") << endl;
//     cout << trie.search("pug") << endl;
//     cout << trie.search("aa") << endl;
// }
