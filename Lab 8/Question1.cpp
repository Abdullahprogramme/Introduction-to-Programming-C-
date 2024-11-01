// Count 7, Question 1

#include <iostream>
using namespace std;

int count7(int n);

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Number of 7s in " << num << " is " << count7(num) << endl;
}

int count7(int n) {
    if (n == 0) {
        return 0;
    }

    if (n < 0) {
        n *= -1;
    }
    
    int count = 0;
    while (n > 0) {
        if (n % 10 == 7) {
            count++;
        }
        n /= 10;
    }

    return count;
}