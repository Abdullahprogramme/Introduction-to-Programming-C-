#include <iostream>

using namespace std;

int main() {
    int score;
    string behavior, participation;

    cout << "Enter the score: ";
    cin >> score;

    cout << "Did the student behave well? (yes/no): ";
    cin >> behavior;

    cout << "Did the student participate in class? (yes/no): ";
    cin >> participation;


    string grade;
    if (score < 50) grade = "F";
    else {
        score += (behavior == "yes") ? 5 : 0;
        score += (participation == "yes") ? 5 : 0;

        if (score > 100) score = 100;

        if (score >= 90) grade = "A";
        else if (score >= 80) grade = "A-";
        else if (score >= 70) grade = "B";
        else if (score >= 60) grade = "C";
        else if (score >= 50) grade = "D";
    }

    cout << "The score is " << score << " and the grade is " << grade << endl;
}