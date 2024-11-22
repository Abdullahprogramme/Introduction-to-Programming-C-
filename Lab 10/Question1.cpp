// Length of a pointer string, Question 1

#include <iostream>

using namespace std;

int main() {
    char str[100];
    char *ptr = str;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    int length = 0;

    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    cout << "Length of the string is: " << length << endl;

    return 0;
}