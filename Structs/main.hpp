// Using structs

#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
    double weight;
};

// pointer based struct
struct PersonPointer {
    string *name;
    int *age;
    double *weight;
};


// complex number struct
struct Complex {
    int real;
    int imaginary;
};

Complex operator+(const Complex &a, const Complex &b) {
    Complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

// addition function of complex numbers and its overloaded operator
Complex add(const Complex &a, const Complex &b) {
    Complex result;
    result = a + b;
    return result;
}


ostream &operator<<(ostream &os, const Complex &c) {
    os << c.real << " + " << c.imaginary << "i";
    return os;
}