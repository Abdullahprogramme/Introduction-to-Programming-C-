// Copying a pointer string, Question 2

#include <iostream>

using namespace std;

int main() {
    char str1[100];
    char *ptr1 = str1;

    cout << "Enter a string: ";
    cin.getline(str1, 100);

    char str2[100];
    char *ptr2 = str2;

    while (*ptr1 != '\0') {
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
    }

    *ptr2 = '\0';

    cout << "Copied string is: " << str2 << endl;

}