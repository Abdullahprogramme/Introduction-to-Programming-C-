// Using structs

#include <iostream>
#include <string>
#include "main.hpp"

using namespace std;

int main() {
    Person person1;
    person1.name = "John";
    person1.age = 21;
    person1.weight = 70.5;

    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "Weight: " << person1.weight << endl;

    Person person2 = {"Jane", 22, 60.5};

    cout << "Name: " << person2.name << endl;
    cout << "Age: " << person2.age << endl;
    cout << "Weight: " << person2.weight << endl;

    PersonPointer personPointer1;

    string name = "John";
    int age = 21;
    double weight = 70.5;

    personPointer1.name = &name;
    personPointer1.age = &age;
    personPointer1.weight = &weight;


    // complex numbers and their addittion
    Complex complex1 = {3, 2};
    Complex complex2 = {-1, 3};

    Complex result = add(complex1, complex2);

    cout << "Real: " << result.real << " Imaginary: " << result.imaginary << endl;

    cout << "Complex1: " << complex1 << endl;
    return 0;
}