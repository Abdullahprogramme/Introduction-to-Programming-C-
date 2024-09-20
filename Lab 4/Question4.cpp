// Prime numbers

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int num_of_primes = 0;

    int i, j = 1;
    while (num_of_primes < 50) {
        i = 2;
        while (i <= j) {
            if (j % i == 0) {
                break;
            }
            i++;
        }
        if (i == j) {
            if (num_of_primes % 10 == 0) {
                cout << endl;
            }
            cout << setw(5) << j << " ";
            num_of_primes++;
        }
        j++;
    }
    return 0;
}