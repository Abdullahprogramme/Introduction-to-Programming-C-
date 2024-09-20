// Pattern

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows and column for square pattern: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << setw(2) << '*' << setw(2);
        }
        cout << endl;
    }

    return 0;
}