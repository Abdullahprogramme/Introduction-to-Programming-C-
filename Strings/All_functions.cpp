#include <iostream>
#include <string>

using namespace std;

void show_stats(string &str);

int main() {
    // Question:
    // 1. Start with the string "Learning C++ is fun and rewarding!".
    // 2. Replace "fun" with "challenging" using the replace() method.
    //    Use both forms of replace() to demonstrate different parameters.
    // 3. Compare the original string with the modified string using compare().
    // 4. Find the position of "rewarding" and replace it with "awesome".
    // 5. Extract the substring "Learning" and append " programming" to it using append().
    // 6. Use insert() to add "truly " before "challenging".
    // 7. Use erase() to remove "C++".
    // 8. Count the number of spaces in the string using a loop and at().
    // 9. Convert the string to uppercase using a loop and modify individual characters.

    // Original string
    string str = "Learning C++ is fun and rewarding!";
    string original_str = str; // Save original string for comparison

    show_stats(str);

    // 1. Display the original string
    cout << "Original String: " << str << endl;
    cout << "Length of the original string: " << str.length() << endl;

    // 2. Replace "fun" with "challenging" using replace() with different parameters
    size_t pos = str.find("fun");
    if (pos != string::npos) {
        str.replace(pos, 3, "challenging"); // Replace by specifying position and length
        cout << "After replacing 'fun' with 'challenging': " << str << endl;
    }

    // Replace "challenging" with "rewarding" using replace with iterator overload
    auto start_it = str.begin() + str.find("challenging");
    auto end_it = start_it + 11; // Length of "challenging" is 11
    str.replace(start_it, end_it, "exciting");
    cout << "After replacing 'challenging' with 'exciting': " << str << endl;

    // 3. Compare the original and modified strings using compare()
    int comparison = str.compare(original_str);
    if (comparison == 0) {
        cout << "The strings are equal.\n";
    } else if (comparison < 0) {
        cout << "The original string is lexicographically less than the modified string.\n";
    } else {
        cout << "The original string is lexicographically greater than the modified string.\n";
    }

    // 4. Find "rewarding" and replace it with "awesome"
    pos = str.find("rewarding");
    if (pos != string::npos) { // npos is: -1 meaning not found
        str.replace(pos, 9, "awesome"); // Replace by specifying position and length
        cout << "After replacing 'rewarding' with 'awesome': " << str << endl;
    }

    // 5. Extract "Learning" and append " programming" to it
    string extracted = str.substr(0, 8); // Extract substring from 0 to 7
    extracted.append(" programming");         // Append " programming"
    cout << "Extracted and appended substring: " << extracted << endl;

    // 6. Insert "truly " before "exciting"
    pos = str.find("exciting");
    if (pos != string::npos) {
        str.insert(pos, "truly "); // Insert "truly " at the found position
        cout << "After inserting 'truly ': " << str << endl;
    }

    // 7. Erase "C++" from the string
    pos = str.find("C++");
    if (pos != string::npos) {
        str.erase(pos, 3); // Erase "C++" (3 characters starting from pos)
        cout << "After erasing 'C++': " << str << endl;
    }

    // 8. Count the number of spaces in the string
    int space_count = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str.at(i) == ' ') { // Use at() to access characters
            ++space_count;
        }
    }
    cout << "Number of spaces in the string: " << space_count << endl;

    // 9. Convert the string to uppercase
    for (char& c : str) { // Use a range-based loop to modify characters
        c = toupper(c);
    }
    cout << "String in uppercase: " << str << endl;

    // Final string result
    cout << "Final modified string: " << str << endl;

    show_stats(str);

    str.append("Another string");
    cout << "After appending '!' with position and length: " << str << endl;
    show_stats(str);

    return 0;
}

void show_stats(string &str) {
    cout << "String which is the word itself: " << str << endl;
    // length is the number of characters, can be different from the capacity
    cout << "Length which is the number of characters: " << str.length() << endl;
    // capacity is the allocated storage, can change depending on the implementation meaning it can be more than the length
    cout << "Capacity which is the allocated storage: " << str.capacity() << endl;
    cout << "Max Size which is the maximum number of characters: " << str.max_size() << endl;
    cout << "Empty which is true if the string is empty: " << (str.empty() ? "Yes" : "No") << endl;
    cout << endl;
}