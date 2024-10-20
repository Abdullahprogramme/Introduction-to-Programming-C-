#include <iostream>

using namespace std;

int main() {
    int arr1_price[] = {32, 45, 67, 89, 12, 34, 56, 78, 90, 23};
    // int arr2_price[] = {12, 34, 56, 78, 90, 23, 32, 45, 67};  this will cause an error as last element is missing
    int arr2_price[] = {12, 34, 56, 78, 90, 23, 32, 45, 67, 0}; // place a zero at the end to avoid the error

    int sum = 0;
    // size function is equivalent to sizeof(arr) / sizeof(arr[0])
    for (int i = 0; i < size(arr1_price); i++) {
        sum += arr1_price[i] + arr2_price[i];
    }

    cout << "The sum of the prices is " << sum << endl;
}