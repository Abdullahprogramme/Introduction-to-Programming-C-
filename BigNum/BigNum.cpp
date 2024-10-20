#include "BigNum.h"
#include <iostream>
#include <cassert>

using namespace std;

void testConstructors() {
    // Test default constructor
    BigNum num1;
    assert(num1.equals(BigNum("0")));

    // Test string constructor
    BigNum num2("12345");
    assert(num2.equals(BigNum("12345")));

    // Test integer constructor
    BigNum num3(67890);
    assert(num3.equals(BigNum("67890")));

    // Test negative number
    BigNum num4("-54321");
    assert(num4.equals(BigNum("-54321")));

    cout << "Constructors test passed!" << endl;
}

void testAddition() {
    BigNum num1("12345");
    BigNum num2("67890");
    BigNum result = num1.add(num2);
    assert(result.equals(BigNum("80235")));

    // Test addition with negative numbers
    BigNum num3("-12345");
    result = num1.add(num3);
    assert(result.equals(BigNum("0")));

    cout << "Addition test passed!" << endl;
}

void testSubtraction() {
    BigNum num1("67890");
    BigNum num2("12345");
    BigNum result = num1.subtract(num2);
    assert(result.equals(BigNum("55545")));

    // Test subtraction with negative numbers
    BigNum num3("-12345");
    result = num1.subtract(num3);
    assert(result.equals(BigNum("80235")));

    cout << "Subtraction test passed!" << endl;
}

void testMultiplication() {
    BigNum num1("123");
    BigNum num2("456");
    BigNum result = num1.multiply(num2);
    assert(result.equals(BigNum("56088")));

    // Test multiplication with negative numbers
    BigNum num3("-123");
    result = num1.multiply(num3);
    assert(result.equals(BigNum("-15129")));

    cout << "Multiplication test passed!" << endl;
}

void testDivision() {
    BigNum num1("56088");
    BigNum num2("456");
    BigNum result = num1.div(num2);
    assert(result.equals(BigNum("123")));

    // Test division with negative numbers
    BigNum num3("-56088");
    result = num1.div(num3);
    assert(result.equals(BigNum("-1")));

    cout << "Division test passed!" << endl;
}

void testModulus() {
    BigNum num1("56088");
    BigNum num2("456");
    BigNum result = num1.mod(num2);
    assert(result.equals(BigNum("0")));

    // Test modulus with negative numbers
    BigNum num3("-56088");
    result = num1.mod(num3);
    assert(result.equals(BigNum("0")));

    cout << "Modulus test passed!" << endl;
}

void testComparison() {
    BigNum num1("12345");
    BigNum num2("67890");
    assert(num1.lessThan(num2));
    assert(num2.greaterThan(num1));
    assert(num1.notEquals(num2));
    assert(num1.equals(BigNum("12345")));

    cout << "Comparison test passed!" << endl;
}

void testIncrementDecrement() {
    BigNum num1("12345");
    num1.increment();
    assert(num1.equals(BigNum("12346")));

    num1.decrement();
    assert(num1.equals(BigNum("12345")));

    BigNum num2("-12345");
    num2.increment();
    assert(num2.equals(BigNum("-12344")));

    num2.decrement();
    assert(num2.equals(BigNum("-12345")));

    cout << "Increment/Decrement test passed!" << endl;
}

void testInputOutput() {
    BigNum num1;
    num1.input();
    num1.print();

    num1.inputFromFile("input.txt");
    num1.printToFile("output.txt");

    cout << "Input/Output test passed!" << endl;
}

int main() {
    testConstructors();
    testAddition();
    testSubtraction();
    testMultiplication();
    testDivision();
    testModulus();
    testComparison();
    testIncrementDecrement();
    testInputOutput();

    cout << "All tests passed!" << endl;

    string num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    BigNum n1(num1), n2(num2);

    n1.add(n2).print();
    n1.subtract(n2).print();
    n1.multiply(n2).print();
    n1.div(n2).print();
    n1.mod(n2).print();
    return 0;
}