// Odd digits

#include <iostream>

using namespace std;

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    bool flag = true;

    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 == 0) {
            flag = false;
            cout << "False" << endl;
            break;
        }
        num /= 10;
    }
    cout << (flag ? "True" : "");
    return 0;
}