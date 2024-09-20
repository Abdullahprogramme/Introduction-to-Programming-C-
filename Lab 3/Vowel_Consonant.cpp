#include <iostream>
using namespace std;

// Vowel consonant function
void vowel_consonant(char letter) {
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
        cout << "Vowel" << endl;
    } else {
        cout << "Consonant" << endl;
    }
}

int main() {
    // Initializing
    char letter;

    // Input letter
    cout << "Enter a character: ";
    cin >> letter;

    if (int(letter) < 65 || (int(letter) > 90 && int(letter) < 97) || int(letter) > 122) {
        cout << "Invalid character" << endl;
        return 0;
    }

    // Output vowel or consonant
    cout << "The character is ";
    vowel_consonant(tolower(letter));

    return 0;
}