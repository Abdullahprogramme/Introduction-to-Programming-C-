#include <iostream>

using namespace std;

int main() {
    int x{5};
    while (x--) {
        cout << x << " ";
    }

    cout << endl;
    x = 5;
    while (--x) {
        cout << x << " ";
    }

    return 0;
}