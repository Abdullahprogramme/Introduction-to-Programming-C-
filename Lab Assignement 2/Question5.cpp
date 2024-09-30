// grade distribution with random numbers

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void grade_distribution() {
    array<int, 30> grades;

    srand(time(0));
    for (int i = 0; i < 30; i++) {
        // generating random number between 0 and 100
        int random = rand() % 101;

        grades[i] = random;
    }

    array<int, 11> freq;

    for (int i = 0; i < 11; i++) { // initializing the frequency array
        freq[i] = 0;
    }

    // counting the frequency of each grade in array grade range
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 11; j++) {
            if (grades[i] / 10 == j) {
                freq[j]++;
            }
        }
    }
    int total = 0;
    // displaying the frequency of each grade
    cout << "Grade Range" << setw(13) << "Frequency" << endl;
    for (int i{0}; i < 11; i++) {
        if (i == 10) {
            cout << "   " << i * 10 << ": " << setw(3) << " ";
        } else {
            cout << "   " << i * 10 << " - " << i * 10 + 9 << ": " << setw(3) << " ";
        }
        
        for (int j = 0; j < freq[i]; j++) {
            cout << "*";
            total++;
        }
        cout << endl;
    }
    cout << "Total number of grades: " << total << endl;
}

int main() {
    grade_distribution();
    return 0;
}