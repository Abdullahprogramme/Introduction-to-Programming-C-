// Vowel counter in pointer string, Question 3

#include <iostream>

using namespace std;

int main() {
    char str1[100];
    char *ptr1 = str1;

    cout << "Enter a string: ";
    cin.getline(str1, 100);

    int vowels = 0;

    while (*ptr1 != '\0') {
        if (*ptr1 == 'a' || *ptr1 == 'e' || *ptr1 == 'i' || *ptr1 == 'o' || *ptr1 == 'u' || *ptr1 == 'A' || *ptr1 == 'E' || *ptr1 == 'I' || *ptr1 == 'O' || *ptr1 == 'U') {
            vowels++;
        }
        ptr1++;
    }

    cout << "Number of vowels in the string is: " << vowels << endl;
}