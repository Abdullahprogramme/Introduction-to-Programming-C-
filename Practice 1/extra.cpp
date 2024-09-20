#include <iostream>

using namespace std;

int main() {


    int grade;
    cout << "Enter your grade: ";
    cin >> grade;

    if (grade >= 90 && grade <= 100) {
        cout << "A";
    } else if (grade >= 80 && grade < 90) {
        cout << "B";
    } else if (grade >= 70 && grade < 80) {
        cout << "C";
    } else if (grade >= 60 && grade < 70) {
        cout << "D";
    } else if (grade >= 0 && grade < 60) {
        cout << "F";
    } else {
        cout << "Invalid grade";
    }

    switch (grade) {
        case 90:
            cout << "A";
            break;
        case 80:
            cout << "B";
            break;
        case 70:
            cout << "C";
            break;
        case 60:
            cout << "D";
            break;
        default:
            cout << "F";
            break;
    }

    // difference between if-else and switch
    // if-else can have multiple conditions
    // switch can only have one condition
    
}