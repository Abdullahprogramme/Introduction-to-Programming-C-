#include <iostream>
using namespace std;

// Computing taxes function
void Single(float salary) {
    float tax;
    if (salary > 0 && salary <= 8350) {
        tax = salary * 0.10;
    } else if (salary > 8350 && salary <= 33950) {
        tax = salary * 0.15;
    } else if (salary > 33950 && salary <= 82250) {
        tax = salary * 0.25;
    } else if (salary > 82250 && salary <= 171550) {
        tax = salary * 0.28;
    } else if (salary > 171550 && salary <= 372950) {
        tax = salary * 0.33;
    } else if (salary > 372950) {
        tax = salary * 0.35;
    } else {
        cout << "Invalid salary" << endl;
    }

    cout << "Your tax deducted salary is: " << salary - tax << endl;
}

void Married_Filing(float salary) {
    float tax;
    if (salary > 0 && salary <= 16700) {
        tax = salary * 0.10;
    } else if (salary > 16700 && salary <= 67900) {
        tax = salary * 0.15;
    } else if (salary > 67900 && salary <= 137050) {
        tax = salary * 0.25;
    } else if (salary > 137050 && salary <= 208850) {
        tax = salary * 0.28;
    } else if (salary > 208850 && salary <= 372950) {
        tax = salary * 0.33;
    } else if (salary > 372950) {
        tax = salary * 0.35;
    } else {
        cout << "Invalid salary" << endl;
    }

    cout << "Your tax deducted salary is: " << salary - tax << endl;
}

void Married_separate(float salary) {
    float tax;
    if (salary > 0 && salary <= 8350) {
        tax = salary * 0.10;
    } else if (salary > 8350 && salary <= 33950) {
        tax = salary * 0.15;
    } else if (salary > 33950 && salary <= 68525) {
        tax = salary * 0.25;
    } else if (salary > 68525 && salary <= 104425) {
        tax = salary * 0.28;
    } else if (salary > 104425 && salary <= 186475) {
        tax = salary * 0.33;
    } else if (salary > 186475) {
        tax = salary * 0.35;
    } else {
        cout << "Invalid salary" << endl;
    }

    cout << "Your tax deducted salary is: " << salary - tax << endl;
}

void Head_Of_HouseHold(float salary) {
    float tax;
    if (salary > 0 && salary <= 11950) {
        tax = salary * 0.10;
    } else if (salary > 11950 && salary <= 45500) {
        tax = salary * 0.15;
    } else if (salary > 45500 && salary <= 117450) {
        tax = salary * 0.25;
    } else if (salary > 117450 && salary <= 190200) {
        tax = salary * 0.28;
    } else if (salary > 190200 && salary <= 372950) {
        tax = salary * 0.33;
    } else if (salary > 372950) {
        tax = salary * 0.35;
    } else {
        cout << "Invalid salary" << endl;
    }

    cout << "Your tax deducted salary is: " << salary - tax << endl;
}

int main() {
    short status;
    float salary;

    cout << "Enter your status (0 for Single, 1 for Married Filing, 2 for Married Separate, 3 for Head of Household): ";
    cin >> status;

    cout << "Enter your salary: ";
    cin >> salary;

    if (status == 0) {
        Single(salary);
    } else if (status == 1) {
        Married_Filing(salary);
    } else if (status == 2) {
        Married_separate(salary);
    } else if (status == 3) {
        Head_Of_HouseHold(salary);
    } else {
        cout << "Invalid status" << endl;
    }

    return 0;
}