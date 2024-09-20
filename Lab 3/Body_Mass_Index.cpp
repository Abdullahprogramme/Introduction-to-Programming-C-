#include <iostream>
using namespace std;

// Body mass index function
void body_mass_index(float weight, float height) {
    float answer = weight / (height * height);
    if (answer < 18.5) {
        cout << "Underweight" << endl;
    } else if (answer >= 18.5 && answer < 25) {
        cout << "Normal" << endl;
    } else if (answer >= 25 && answer < 30) {
        cout << "Overweight" << endl;
    } else {
        cout << "Obese" << endl;
    }
}

int main() {
    // Initializing
    float weight, height;

    // Input weight and height
    cout << "Enter weight (kg): ";
    cin >> weight;
    cout << "Enter height (m): ";
    cin >> height;

    // Output body mass index
    cout << "You are ";
    body_mass_index(weight, height);
    

    return 0;
}