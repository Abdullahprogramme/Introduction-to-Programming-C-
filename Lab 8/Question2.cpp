// Factor, Question 2

#include <iostream>
using namespace std;

bool isFactor(int num1, int num2);

int main() {
    int num1, num2, tryAgain;

    do {
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        cout << (isFactor(num1, num2) == 1 ? "The second is the factor of the first" : "The second is not the factor of the first") << endl;

        cout << "\nTry again? (1 for yes, 0 for no): ";
        cin >> tryAgain;
    } while (tryAgain == 1);
    
    return 0;
}

bool isFactor(int num1, int num2) {
    if (num2 == 0) {
        return false;
    }
    return num1 % num2 == 0;
}