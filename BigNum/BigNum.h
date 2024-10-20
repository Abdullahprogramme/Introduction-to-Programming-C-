#ifndef BIG_NUM_H
#define BIG_NUM_H

#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

class BigNum {
private:
    
    // your choice whether to use a vector<char>
    // or a char* for dynamic 1D array of char
    // or a linked list of character data
    // any other private attributes you feel
    // but no static array
    
    vector<char> num = {};
    bool ispositive;

    void add_digit(char digit) {
        num.push_back(digit);
        // example: 123 -> 1234
    }

    void removeLeadingZeros() {
        auto it = find_if(num.begin(), num.end(), [](char c) { return c != '0'; });
        if (it != num.end()) {
            num.erase(num.begin(), it);
        } else {
            num = {'0'};
        }
        // example: 000123 -> 123 or 0000 -> 0
    }

    // Helper method to add two positive BigNum objects
    BigNum addPositive(const BigNum& other) const {
        BigNum result;
        result.clear();

        int carry = 0;
        size_t i = num.size();
        size_t j = other.num.size();

        while (i > 0 || j > 0 || carry > 0) {
            int digit1 = (i > 0) ? num[--i] - '0' : 0;
            int digit2 = (j > 0) ? other.num[--j] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.num.insert(result.num.begin(), (sum % 10) + '0');
        }

        return result;
    }

    // Helper method to subtract two positive BigNum objects
    BigNum subtractPositive(const BigNum& other) const {
        BigNum result;
        result.clear();

        int borrow = 0;
        size_t i = num.size();
        size_t j = other.num.size();

        while (i > 0 || j > 0) {
            int digit1 = (i > 0) ? num[--i] - '0' : 0;
            int digit2 = (j > 0) ? other.num[--j] - '0' : 0;
            int diff = digit1 - digit2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.num.insert(result.num.begin(), diff + '0');
        }

        result.removeLeadingZeros();
        return result;
    }

    // Helper method to compare two positive BigNum objects
    int comparePositive(const BigNum& other) const {
        if (num.size() != other.num.size()) {
            return num.size() > other.num.size() ? 1 : -1;
        }
        for (size_t i = 0; i < num.size(); ++i) {
            if (num[i] != other.num[i]) {
                return num[i] > other.num[i] ? 1 : -1;
            }
        }
        return 0;
    }

public:

    // Constructors and Destructor
    BigNum() { // default constructor
        ispositive = true;
        num.push_back('0'); // default initialization value should be '0'
    }

    // Copy constructor
    BigNum(const BigNum& bigNum) : num(bigNum.num), ispositive(bigNum.ispositive) {
        // The vector and boolean are copied directly
    }
         
    BigNum(const string& bigStr) { // bigStr is a string e.g. �348723482�
        if (bigStr.empty()) {
            ispositive = true;
            num.push_back('0');
            return;
        }

        size_t start = 0;
        if (bigStr[0] == '-') {
            ispositive = false;
            start = 1;
        } else if (bigStr[0] == '+') {
            ispositive = true;
            start = 1;
        } else {
            ispositive = true;
        }

        for (size_t i = start; i < bigStr.size(); ++i) {
            if (isdigit(bigStr[i])) {
                num.push_back(bigStr[i]);
            } else {
                throw invalid_argument("Invalid character in number string");
            }
        }

        removeLeadingZeros();
    }
   
    BigNum(const int num) { // num is an integer e.g. 487234985 or -234232323
        if (num == 0) {
            ispositive = true;
            this->num.push_back('0');
            return;
        }

        if (num < 0) {
            ispositive = false;
        } else {
            ispositive = true;
        }

        int temp = abs(num);
        while (temp > 0) {
            add_digit(temp % 10 + '0');
            temp /= 10;
        }

        reverse(this->num.begin(), this->num.end());

        removeLeadingZeros();
    }

    ~BigNum() {                 // delete dynamic array, if you are using dynamic array
        clear();
    }

    // Input/Output Operations                                
    void input() { // clears current number and sets the number input from user.
        string inputStr;
        cout << "Enter a number: ";
        cin >> inputStr;

        // Clear the current value
        clear();

        if (inputStr.empty()) {
            ispositive = true;
            num.push_back('0');
            return;
        }

        size_t start = 0;
        if (inputStr[0] == '-') {
            ispositive = false;
            start = 1;
        } else if (inputStr[0] == '+') {
            ispositive = true;
            start = 1;
        } else {
            ispositive = true;
        }

        for (size_t i = start; i < inputStr.size(); ++i) {
            if (isdigit(inputStr[i])) {
                num.push_back(inputStr[i]);
            } else {
                throw invalid_argument("Invalid character in number string");
            }
        }

        removeLeadingZeros();
    }

    void print() const { // prints the number to screen. (comma separate after 3-digit
                         // groups e.g. 12,345,678)
        if (!ispositive) {
            cout << '-';
        }

        for (size_t i = 0; i < num.size(); ++i) {
            cout << num[i];
            if ((num.size() - i - 1) % 3 == 0 && i != num.size() - 1) {
                cout << ',';
            }
        }
        cout << endl;
    }
        
    void inputFromFile(const string& fileName) { // clears current number and sets the number
        ifstream file(fileName); // given in file. see clear() helper method
        if (!file.is_open()) {
            throw runtime_error("Could not open file");
        }

        string inputStr;
        file >> inputStr;
        file.close();

        // Clear the current value
        clear();

        if (inputStr.empty()) {
            ispositive = true;
            num.push_back('0');
            return;
        }

        size_t start = 0;
        if (inputStr[0] == '-') {
            ispositive = false;
            start = 1;
        } else if (inputStr[0] == '+') {
            ispositive = true;
            start = 1;
        } else {
            ispositive = true;
        }

        for (size_t i = start; i < inputStr.size(); ++i) {
            if (isdigit(inputStr[i])) {
                num.push_back(inputStr[i]);
            } else {
                throw invalid_argument("Invalid character in number string");
            }
        }

        removeLeadingZeros();
    }
   
    void printToFile(const string& fileName) const { // prints the number to file
        ofstream file(fileName);
        if (!file.is_open()) {
            throw runtime_error("Could not open file");
        }

        if (!ispositive) {
            file << '-';
        }

        for (size_t i = 0; i < num.size(); ++i) {
            file << num[i];
            if ((num.size() - i - 1) % 3 == 0 && i != num.size() - 1) {
                file << ',';
            }
        }
        file << endl;
        file.close();
    }

    // // Initialization/Assignment Operations
    void copy(const BigNum& bigNum) {
        if (this == &bigNum) {
            return; // Handle self-assignment
        }

        // Copy the vector and boolean directly
        num = bigNum.num;
        ispositive = bigNum.ispositive;
    }

    void operator=(const BigNum& bigNum) {
        if (this == &bigNum) {
            return; // Handle self-assignment
        }

        // Copy the vector and boolean directly
        num = bigNum.num;
        ispositive = bigNum.ispositive;
    }
 
    void zerofy() { // initializes the number to 0
        clear();
        ispositive = true;
        num.push_back('0');
    }

    // // Arithmetic Operations: Addition                    
    void increment() { // increments the whole number by 1 (not every digit)
        if (!ispositive) {
            // Handle negative numbers
            size_t i = num.size();
            while (i > 0) {
                --i;
                if (num[i] > '0') {
                    num[i]--;
                    break;
                } else {
                    num[i] = '9';
                }
            }
            removeLeadingZeros();
            if (num.size() == 1 && num[0] == '0') {
                ispositive = true;
            }
        } else {
            // Handle positive numbers
            size_t i = num.size();
            while (i > 0) {
                --i;
                if (num[i] < '9') {
                    num[i]++;
                    break;
                } else {
                    num[i] = '0';
                }
            }
            if (num[0] == '0') {
                num.insert(num.begin(), '1');
            }
        }
    }
      
    BigNum add(const BigNum& other) const { // like c = a+b; e.g. c = a.add(b);
        BigNum result;

        if (ispositive == other.ispositive) {
            // Both numbers have the same sign
            result = addPositive(other);
            result.ispositive = ispositive;
        } else {
            // Numbers have different signs
            if (ispositive) {
                // this is positive, other is negative
                if (*this >= other) {
                    result = subtractPositive(other);
                    result.ispositive = true;
                } else {
                    result = other.subtractPositive(*this);
                    result.ispositive = false;
                }
            } else {
                // this is negative, other is positive
                if (*this <= other) {
                    result = other.subtractPositive(*this);
                    result.ispositive = true;
                } else {
                    result = subtractPositive(other);
                    result.ispositive = false;
                }
            }
        }

        result.removeLeadingZeros();
        return result;
    }

    // Comparison operators for internal use
    bool operator>=(const BigNum& other) const {
        if (num.size() != other.num.size()) {
            return num.size() > other.num.size();
        }
        for (size_t i = 0; i < num.size(); ++i) {
            if (num[i] != other.num[i]) {
                return num[i] > other.num[i];
            }
        }
        return true;
    }

    bool operator<=(const BigNum& other) const {
        if (num.size() != other.num.size()) {
            return num.size() < other.num.size();
        }
        for (size_t i = 0; i < num.size(); ++i) {
            if (num[i] != other.num[i]) {
                return num[i] < other.num[i];
            }
        }
        return true;
    }
             
    BigNum add(const int num) const { // like c = a+2; e.g. c = a.add(2);
        BigNum otherBigNum(num);
        return add(otherBigNum);
    }
 
    void compoundAdd(const BigNum& bigNum) { // like a+=b; e.g. a.compoundAdd(b);
        *this = this->add(bigNum);
    }
    
    void compoundAdd(const int num) { // like a+=2; e.g. a.compoundAdd(2);
        BigNum otherBigNum(num);
        this->compoundAdd(otherBigNum);
    }

    // Arithmetic Operations: Subtraction                
    void decrement() { // decrements the whole number by 1 (not every digit)
        if (ispositive) {
            // Handle positive numbers
            size_t i = num.size();
            while (i > 0) {
                --i;
                if (num[i] > '0') {
                    num[i]--;
                    break;
                } else {
                    num[i] = '9';
                }
            }
            removeLeadingZeros();
            if (num.size() == 1 && num[0] == '0') {
                ispositive = false;
            }
        } else {
            // Handle negative numbers
            size_t i = num.size();
            while (i > 0) {
                --i;
                if (num[i] < '9') {
                    num[i]++;
                    break;
                } else {
                    num[i] = '0';
                }
            }
            if (num[0] == '0') {
                num.insert(num.begin(), '1');
            }
        }
    }
         
    BigNum subtract(const BigNum& other) const {
        BigNum result;

        if (ispositive == other.ispositive) {
            // Both numbers have the same sign
            if (*this >= other) {
                result = subtractPositive(other);
                result.ispositive = ispositive;
            } else {
                result = other.subtractPositive(*this);
                result.ispositive = !ispositive;
            }
        } else {
            // Numbers have different signs
            result = addPositive(other);
            result.ispositive = ispositive;
        }

        result.removeLeadingZeros();
        return result;
    }
              
    BigNum subtract(const int num) const { // like c = a-2; e.g. c = a.subtract(2);
        BigNum otherBigNum(num);
        return subtract(otherBigNum);
    }
 
    void compoundSubract(const BigNum& bigNum) { // like a-=b; e.g. a.compoundSubtract(b);
        *this = this->subtract(bigNum);
    }

    void compoundSubtract(const int num) { // like a-=2; e.g. a.compoundSubtract(2);
        BigNum otherBigNum(num);
        this->compoundSubract(otherBigNum);
    }

    // Arithmetic Operations: Multiplication and Division
    BigNum multiply(const BigNum& other) const { // like c = a*b; e.g. c = a.multiply(b);
        BigNum result;
        result.clear();
        result.num.resize(num.size() + other.num.size(), '0');

        for (int i = num.size() - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = other.num.size() - 1; j >= 0; --j) {
                int product = (num[i] - '0') * (other.num[j] - '0') + (result.num[i + j + 1] - '0') + carry;
                carry = product / 10;
                result.num[i + j + 1] = (product % 10) + '0';
            }
            result.num[i] += carry;
        }

        result.removeLeadingZeros();
        result.ispositive = (ispositive == other.ispositive);
        return result;
    }
   
    BigNum div(const BigNum& other) const { // integer division (/) operator
        if (other.num.size() == 1 && other.num[0] == '0') {
            cout << "Invalid operation" << endl;
            return BigNum(0);
        }

        BigNum result;
        result.clear();
        BigNum current;
        current.clear();
        current.ispositive = true;

        for (size_t i = 0; i < num.size(); ++i) {
            current.num.push_back(num[i]);
            current.removeLeadingZeros();

            int count = 0;
            while (current.comparePositive(other) >= 0) {
                current = current.subtractPositive(other);
                count++;
            }
            result.num.push_back(count + '0');
        }

        result.removeLeadingZeros();
        result.ispositive = (ispositive == other.ispositive);
        return result;
    }
      
    BigNum mod(const BigNum& other) const { // remainder (%) operator
        if (other.num.size() == 1 && other.num[0] == '0') {
            cout << "Invalid operation" << endl;
            return BigNum(0);
        }

        BigNum current;
        current.clear();
        current.ispositive = true;

        for (size_t i = 0; i < num.size(); ++i) {
            current.num.push_back(num[i]);
            current.removeLeadingZeros();

            while (current.comparePositive(other) >= 0) {
                current = current.subtractPositive(other);
            }
        }

        current.ispositive = ispositive;
        return current;
    }

    // Comparison Operations:
    bool equals(const BigNum& bigNum) const {
        // Check if both numbers have the same sign
        if (ispositive != bigNum.ispositive) {
            return false;
        }

        // Check if both numbers have the same size
        if (num.size() != bigNum.num.size()) {
            return false;
        }

        // Check if all digits are the same
        for (size_t i = 0; i < num.size(); ++i) {
            if (num[i] != bigNum.num[i]) {
                return false;
            }
        }

        return true;
    }

    bool notEquals(const BigNum& bigNum) const {
        // Return the negation of the equals method
        return !equals(bigNum);
    }

    bool lessThan(const BigNum& bigNum) {
        // returns true if the calling object is less than bigNum
        if (ispositive && !bigNum.ispositive) {
            return false;
        } else if (!ispositive && bigNum.ispositive) {
            return true;
        } else if (ispositive && bigNum.ispositive) {
            return comparePositive(bigNum) < 0;
        } else {
            return comparePositive(bigNum) > 0;
        }
    }

    bool greaterThan(const BigNum& bigNum) {
        // returns true if the calling object is greater than bigNum
        return !equals(bigNum) && !lessThan(bigNum);
    }

private:

    void clear() { // equivalent to deleting current dynamic array. must be called in input methods
        num.clear();
        ispositive = true;
    }
};

#endif