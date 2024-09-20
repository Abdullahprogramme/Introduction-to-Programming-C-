// Dice roller

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(0)));
    int roll;

    for (unsigned int i = 1; i <= 10; i++) {
        roll = rand() % 6 + 1;
        switch (roll) {
            case 1: cout << "Roll " << i << ": " << roll << " - You need to roll better" << '.' << endl; break;
            case 2:
            case 3:
            case 4:
            case 5: cout << "Roll " << i << ": " << roll << " - You rolled " << roll << '.' << endl; break;
            case 6: cout << "Roll " << i << ": " << roll << " - Congratulations! You rolled the highest number." << endl; break;
        }
    }

    return 0;
}