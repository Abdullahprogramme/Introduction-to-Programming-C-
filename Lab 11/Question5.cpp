// recursive pattern, Question 5

#include <iostream>
using namespace std;

void writeChars(int n);

int main() {
    int n;
    cout << "Enter a number 'n' >= 0: ";
    cin >> n;

    writeChars(n);
    cout << endl;
    return 0;
}

void writeChars(int n) {
    if (n == 0) cout << "";
    else if (n == 1) {
        cout << "*";
    } else if (n == 2) {
        cout << "**";
    } else {
        cout << "<";
        writeChars(n - 2);
        cout << ">";
    }
}