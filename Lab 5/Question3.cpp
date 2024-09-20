// Hexa to Decimal conversion

#include <iostream>
#include <cmath>

using namespace std;

int converter(char hex) {
    // using ascii
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else {
        return hex - 'A' + 10;
    }
}

int main() {
    int total = 0;
    string hex;

    cout << "Enter a hexadecimal number: ";
    cin >> hex;

    for (int i = hex.length() - 1; i >= 0; i--) {
        total += converter(hex[i]) * pow(16, hex.length() - 1 - i);
    }

    cout << "Decimal: " << total << endl;

    return 0;
}