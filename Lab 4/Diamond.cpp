// Diamond pattern

#include <iostream>
using namespace std;

void Diamond(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for(int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for(int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void New_Pattern(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for(int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    cout << "a: " << a << " b: " << b << endl;
    return gcd(b, a % b);
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    Diamond(n);
    cout << endl;
    New_Pattern(n);

    cout << gcd(10, 15) << endl;
    cout << "----------------" << endl;
    cout << gcd(15, 10) << endl;
    return 0;
}