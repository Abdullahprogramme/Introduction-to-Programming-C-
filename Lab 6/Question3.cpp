// percentage of even

#include <iostream>
#include <array>
#include <iomanip>

using namespace std;


void percentage_of_even(int *arr) {
    int even = 0;
    int total = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {
            even++;
        }
        total++;
    }

    double final = (static_cast<double>(even) / static_cast<double>(total)) * 100;
    cout << fixed << setprecision(1);
    cout << "Percentage of even numbers: " << final << endl;
}

int main() {
    array<int, 10> arr;
    cout << "Enter 10 integer numbers\n";
    for (int i = 0; i < 10; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    percentage_of_even(arr.data());
    return 0;
}