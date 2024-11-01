// Centered Average, Question 4

#include <iostream>
#include <algorithm>

using namespace std;

int centeredAverage(int *nums, int size);

int main() {
    int nums[] = {-4, 5, 6, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Centered average: " << centeredAverage(nums, sizeof(nums) / sizeof(nums[0])) << endl;
    return 0;
}

int centeredAverage(int *nums, int size) {
    // Sort the built in array
    sort(nums, nums + size);
    
    // Remove the smallest and largest values
    int sum = 0;
    for (int i = 1; i < size - 1; ++i) {
        sum += nums[i];
    }
    
    // Calculate the average using integer division
    int average = sum / (size - 2);
    return average;
}