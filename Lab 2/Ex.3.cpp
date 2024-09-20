// Money made smaller in terms of number

#include <iostream>
using namespace std;

int main() {

    cout << "Enter the amount of money you have: ";

    double total;
    cin >> total;

    int dollar = (int)total;
    int remainder = (total - dollar) * 100 + 0.5; // example: (3.45 - 3) * 100 = 45

    int quarter = remainder / 25;
    remainder %= 25;

    int dime = remainder / 10;
    remainder %= 10;

    int nickel = remainder / 5;
    remainder %= 5;

    int penny = remainder;


    cout << "You have " << dollar << " dollars, " << quarter << " quarters, " << dime << " dimes, " << nickel << " nickels, and " << penny << " pennies." << endl;

    // int dollar, quarter, dime, nickel;
    // double penny, total;

    // cin >> total;

    // // seperating them into dollars, quarters, dimes, nickels, and pennies
    // dollar = total / 1;
    // total -= dollar;

    // quarter = total / 0.25;
    // total -= quarter * 0.25;

    // dime = total / 0.1;
    // total -= dime * 0.1;

    // nickel = total / 0.05;
    // total -= nickel * 0.05;

    // penny = total * 100;
    // total -= penny * 0.01;

    // cout << "You have " << dollar << " dollars, " << quarter << " quarters, " << dime << " dimes, " << nickel << " nickels, and " << penny << " pennies." << endl;
}