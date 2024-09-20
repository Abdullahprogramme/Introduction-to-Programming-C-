#include <iostream>
using namespace std;
#include <iomanip>

int main() {
    int N, J;
    cout << "Enter the number J: ";
    cin >> J;
    N = 1;
    while (N++ <= J) {
        if (N % 2 == 0) {
            cout << N << endl;
        }
    }

    cout << "Enter the number J:";
    cin >> J;
    int Sum = 0;
    while (J >= 0) {
        cout << J << endl;
        Sum += J;
        cout << "Enter the number J: ";
        cin >> J;
    }
    cout << "Sum = " << Sum << endl;

    double a = 13.5;
    cout << fixed << setprecision(0) << a << endl;



    cout << "Number" << setw(13) << "Square" << setw(13) << "Cube" << endl;
    for(unsigned int i{1}; i <= 10; ++i) { 
        cout << setw(6) << i << setw(13) << i * i << setw(13) << i * i * i << endl;
    }

    int n = 4;
    for(int i = n; i > 0; i--){
        cout << string(i, '*') << endl;
    }

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    n = 4;
    for (int i = n; i > 0; i--) {
        for (int j = n; j > n-i; j--) {
            cout << j;
        }
        cout << endl;
    }
}