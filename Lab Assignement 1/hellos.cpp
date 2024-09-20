// Hellos

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of times you want to print 'Hello': ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (i % 100 >= 11 && i % 100 <= 13) {
            cout << i << "th Hello" << endl;
        } else if (i % 10 == 1) {
            cout << i << "st Hello" << endl;
        } else if (i % 10 == 2) {
            cout << i << "nd Hello" << endl;
        } else if (i % 10 == 3) {
            cout << i << "rd Hello" << endl;
        } else {
            cout << i << "th Hello" << endl;
        }
    }

    return 0;
}