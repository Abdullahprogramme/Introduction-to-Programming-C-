// lowercase number frequency counter

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void lowercase_number_frequency_counter() {
    array<int, 100> lower;

    srand(time(0));

    for (int i = 0; i < 100; i++) {
        // generating random number between 97 and 122  
        int random = rand() % 26 + 97;

        lower[i] = random;
    }

    array<int, 26> freq;

    for (int i = 0; i < 26; i++) { // initializing the frequency array
        freq[i] = 0;
    }

    // counting the frequency of each lowercase letter in array lower
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 26; j++) {
            if (lower[i] == j + 97) {
                freq[j]++;
            }
        }
    }

    // displaying the frequency of each lowercase letter

    cout << "Character" << setw(13) << "Frequency" << endl;
    for (int i{0}; i < 26; i++) {
        cout << "   " << static_cast<char>(i + 97) << setw(13) << freq[i] << endl;
    }
    
}

int main() {
    lowercase_number_frequency_counter();
    return 0;
}