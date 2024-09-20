// Upper Diamond Pattern with numbers

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (unsigned int i = 1; i <= n; i++) {
        for (unsigned int j = n - i; j > 0; j--) {
            cout << " ";
        }
        for (unsigned int j = 1; j <= i; j++) {
            cout << j;
        }
        for (unsigned int j = i - 1; j > 0; j--) {
            cout << j;
        }
        cout << endl;
    }
    
    return 0;
}