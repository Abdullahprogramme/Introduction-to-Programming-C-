// Abdullah Tariq, 29123
// Description: This program converts a number to its English equivalent.
// It can convert numbers up to from -999,999 to 999,999.

#include <iostream>
#include <string>
using namespace std;

string units(int number) {
    switch (number) {
        case 1: return "One";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        default: return "";
    }
}

string tens(int number) {
    switch (number) {
        case 10: return "Ten";
        case 11: return "Eleven";
        case 12: return "Twelve";
        case 13: return "Thirteen";
        case 14: return "Fourteen";
        case 15: return "Fifteen";
        case 16: return "Sixteen";
        case 17: return "Seventeen";
        case 18: return "Eighteen";
        case 19: return "Nineteen";
        default: return "";
    }
}

string tens_multiple(int number) {
    switch (number) {
        case 2: return "Twenty";
        case 3: return "Thirty";
        case 4: return "Forty";
        case 5: return "Fifty";
        case 6: return "Sixty";
        case 7: return "Seventy";
        case 8: return "Eighty";
        case 9: return "Ninety";
        default: return "";
    }
}

string converter(int part) {
    string final = "";

    if (part >= 100) { // checking if the number is greater than 100
        final += units(part / 100) + " Hundred "; // converting the hundreds
        part %= 100; // getting the remainder
    }

    if (part >= 20) { // checking if the number is greater than 20
        final += tens_multiple(part / 10) + " "; // converting the tens
        part %= 10; // getting the remainder
    } else if (part >= 10) { // checking if the number is greater than 10
        final += tens(part) + " "; // converting the tens
        return final; // returning the final result
    }

    if (part > 0) { // checking if the number is greater than 0
        final += units(part) + " "; // converting the units
    }

    return final; // returning the final result
}

string num_to_word(int number) {
    if (number == 0) { // conversion of direct zero
        cout << "Zero" << endl;
    }

    string result = "";

    if (number < 0) { // checking if number is negative
        result += "Negative ";
        number = -number;
    }

    // splitting the number in thousands and hundreds
    int thousands = number / 1000;
    int hundreds = number % 1000; // remainder is hundreds

    if (thousands > 0) {
        result += converter(thousands) + "Thousand "; // converting the thousands and adding the suffix
    }

    if (hundreds > 0) {
        result += converter(hundreds); // converting the hundreds
    }
    return result;
}

int main() {
    int number;
    cout << "Enter a number between -999,999 and 999,999: ";
    cin >> number;

    if (number < -999999 || number > 999999) { //checking to see if number is in range
        cout << "Number out of range." << endl;
        return 1;
    }

    cout << "The conversion of " << number << " is: " << num_to_word(number) << endl;
    return 0;
}