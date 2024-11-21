// string functions and implementation

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1;

    // comparing strings
    if (s1 == s2) {
        cout << "s1 and s2 are equal" << endl;
    } else {
        cout << "s1 and s2 are not equal" << endl;
    }

    // with method
    if (s1.compare(s2) == 0) {
        cout << "s1 and s2 are equal" << endl;
    } else {
        cout << "s1 and s2 are not equal" << endl;
    }

    // with variations
    int result = s1.compare(0, 5, s2);
    if (result == 0) {
        cout << "s1 and s2 are equal" << endl;
    } else if (result < 0) {
        cout << "s1 is less than s2" << endl;
    } else {
        cout << "s1 is greater than s2" << endl;
    }

    // concatenating strings
    s1 += ", how are you?";
    cout << s1 << endl;
    s3.append("!");
    s3.append("!", 1, 1);
    cout << s3 << endl;

    // finding substring
    string s4 = "Hello, how are you?";
    int index = s4.find("are");
    cout << "Substring found at index: " << index << endl;

    // getting substring
    string s5 = s4.substr(index);
    cout << "Substring: " << s5 << endl;

    // getting length
    cout << "Length of s4: " << s4.length() << endl;

    // getting character at index
    cout << "Character at index 7: " << s4.at(7) << endl;

    // getting c-string
    const char* cstr = s4.c_str();
    cout << "C-string: " << cstr << endl;

    string new_str1; 
    int new_str2;
    cout << "Enter a string: ";

    cin >> new_str1;
    cout << "String 1: " << new_str1 << endl;

    // clear buffer for the second input if the first input itself has two words such as "Hello 10"
    cin.clear(); // clear the error flag
    cin.ignore(10000, '\n'); // ignore the next 10000 characters or until a newline is encountered
    cin >> new_str2;    
    cout << "String 2: " << new_str2 << endl;
}