// Printing n first letters all permutations of a string

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void permute(string str, string out, vector<string> &v);

int main() {
    int n;
    cout << "Enter the number of letters: ";
    cin >> n;

    string str = "";
    for (int i = 0; i < n; i++) {
        str += 'a' + i;
    }

    vector<string> v;

    permute(str, "", v);

    for (auto &s : v) {
        cout << s << " ";
    }

    return 0;
}

void permute(string str, string out, vector<string> &v) {
    if (str.size() == 0) {
        v.push_back(out);
        return;
    }

    for (int i = 0; i < str.size(); i++) {
        permute(str.substr(1), out + str[0], v);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}