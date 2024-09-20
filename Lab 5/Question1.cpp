// Running sum

#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    for (unsigned int i = 1; i <= n; i++) {
        sum += i;

        for (unsigned int j = 1; j <= i; j++) {
            if (j == 1) {
                cout << j;
            } else {
                cout << " + " << j;
            }
            // ternay method: cout << (j == 1 ? "" : " + ") << j;
        }
        cout << " = " << sum << endl;
    }
    
    return 0;
}