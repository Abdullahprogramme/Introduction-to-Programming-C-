// Denary to Binary 3*3 matrix, Question 4

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string denary_to_binary(int &n);

int main() {
    int n;
    cout << "Enter a number: ";
    while (cin >> n && n != 0) {
        string binary = denary_to_binary(n);
        cout << "The binary is: " << binary << endl;

        // Print the 3x3 matrix
        for(unsigned int i = 0; i < binary.length(); ++i) {
            cout << (binary[i] == '1' ? "T" : "H") << " ";
            if ((i + 1) % 3 == 0) {
                cout << endl;
            }
        }

        cout << "Enter a number: ";
    }

    return 0;
}

string denary_to_binary(int &n) {
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    binary = string(9 - binary.length(), '0') + binary;
    return binary;
}