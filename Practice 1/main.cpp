#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int main() {

    
    // ofstream Myfile("example.txt", ios::app);

    // Myfile << "Files can be tricky, but it is fun enough!\n";
    // Myfile.close();

    // string myText;

    // ifstream MyReadFile("example.txt");

    // while (getline (MyReadFile, myText)) {
    //     cout << myText << '\n';
    // }

    // MyReadFile.close();

    // cout << "IBA \r KHI";
    
    // int ans = 5 + 7 / 10 * 5.0;
    // cout << ans;

    int a = 10;
    short b = 3;
    long c = 10;
    long long d = 1234555;

    // difference between these types is the size of memory they occupy
    // short is 2 bytes
    // int is 4 bytes
    // long is 8 bytes
    // long long is 16 bytes

    float e = 10.0;
    double f = 10.0;
    long double g = 10.0;

    // difference between these types is the precision they provide
    // float is 6 decimal places, 32 bits
    // double is 15 decimal places, 64 bits
    // long double is 18 decimal places, 80 bits

    char h = 'a';
    wchar_t j = L'a';
    char16_t k = u'a';
    char32_t l = U'a';
    string i = "Hello World";

    // char is 1 byte
    // wchar_t is 2 bytes, wide character
    // char16_t is 2 bytes, unicode character
    // char32_t is 4 bytes
    // string is a sequence of characters

    // type casting

    int m = 10;
    double n = 10.0;    

    // type casting between different types, meaning all the types are compatible
    // int to double
    double o = (double) m;
    double p = double(m);

    // double to int
    int q = (int) n;
    int r = int(n);

    // type casting between incompatible types
    // int to char
    char s = (char) m;
    char t = char(m);

    // char to int
    int u = (int) h;
    int v = int(h);

    // type casting between incompatible types
    // int to string
    string w = to_string(m); // another way to convert int to string: string(m)
    
    // string to int
    int x = stoi("11");

    // string to double
    double y = stod("11");

    // string to long
    long z = stol("11");

    // string to long long
    long long aa = stoll("11");

    // string to float
    float ab = stof("11");

    // string to long double
    long double ac = stold("11");

    // string to char
    char ad = i[0];

    // char to string
    string ae = string(1, h);

    // char to int
    int af = h - '0';

    bool leap;
    int year = 2020;

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                leap = true;
            } else {
                leap = false;
            }
        } else {
            leap = true;
        }
    } else {
        leap = false;
    }

    cout << (leap ? "True" : "False") << endl;

    std::string s1 {"Hello, "};
    std::string s2 {s1 + "World"};
    std::string s3 {s2 + "!"};
    std::cout << s3 << std::endl;

    // writing a regular expression in C++
    // regular expression is a sequence of characters that define a search pattern
    // it is used to search for a specific pattern in a string
    // it is used to validate the input

    // extracting the email out of a sentence
    string str = "My email is: abdtariq78@gmail.com";
    regex reg ("([a-zA-Z0-9._%+-]+)@([a-zA-Z0-9.-]+)\\.([a-zA-Z]{2,})");
    smatch match;

    if (regex_search(str, match, reg)) {
        cout << match.str(0) << endl;
    }

}