// Dudeney numbers, Question 1

#include <iostream>
#include <cmath>

using namespace std;

bool isDudeney(int &n);


int main() {
    for(int i{1}; i < 20000 ; ++i) {
        if (isDudeney(i)) {
            cout << i << " is a Dudeney number." << endl;
        }
    }

    return 0;
}

bool isDudeney(int &n) {
    int sum = 0;
    int temp = n;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return pow(sum, 3) == n;
}