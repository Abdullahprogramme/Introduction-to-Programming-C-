#include <iostream>
#include <string>
#include <array>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int maths;
    int Phy;
    int Chem;
    int Total;
    int Rank;
};

bool compareTwoStudents(Student s1, Student s2);
void rankStudents(array<Student, 3> &students);
void sortStudents(array<Student, 3> &students);

int main() {
    array<Student, 3> students;

    for (int i = 0; i < 3; i++) {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter the marks in Maths: ";
        cin >> students[i].maths;
        cout << "Enter the marks in Physics: ";
        cin >> students[i].Phy;
        cout << "Enter the marks in Chemistry: ";
        cin >> students[i].Chem;
        students[i].Total = students[i].maths + students[i].Phy + students[i].Chem;
    }

    rankStudents(students);

    cout << setw(10) << "Name" << setw(10) << "Maths" << setw(10) << "Physics" << setw(10) << "Chemistry" << setw(10) << "Total" << setw(10) << "Rank" << endl;
    // Display the details of the students sorted by rank
    for (int i = 0; i < 3; i++) {
        cout << setw(10) << students[i].name << setw(10) << students[i].maths << setw(10) << students[i].Phy << setw(10) << students[i].Chem << setw(10) << students[i].Total << setw(10) << students[i].Rank << endl;
    }

    return 0;
}

bool compareTwoStudents(Student s1, Student s2) {
    // comparision criteria:
    // 1. Based on total marks
    // 2. If total marks are same, then based on marks in Maths
    // 3. If marks in Maths are also same, then based on marks in Physics
    // 4. If marks in Physics are also same, then based on marks in Chemistry
    // 5. If marks in Chemistry are also same, then any order is fine

    if (s1.Total != s2.Total) {
        return s1.Total > s2.Total;
    }

    if (s1.maths != s2.maths) {
        return s1.maths > s2.maths;
    }

    if (s1.Phy != s2.Phy) {
        return s1.Phy > s2.Phy;
    }

    return s1.Chem > s2.Chem;
}

void rankStudents(array<Student, 3> &students) {
    sortStudents(students);

    for (int i = 0; i < 3; i++) {
        students[i].Rank = i + 1;
    }
}

void sortStudents(array<Student, 3> &students) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (!compareTwoStudents(students[i], students[j])) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Output:
// Enter the name of student 1: John
// Enter the marks in Maths: 90
// Enter the marks in Physics: 80
// Enter the marks in Chemistry: 70
// Enter the name of student 2: Jane
// Enter the marks in Maths: 80
// Enter the marks in Physics: 70
// Enter the marks in Chemistry: 60
// Enter the name of student 3: Jack
// Enter the marks in Maths: 70
// Enter the marks in Physics: 60
// Enter the marks in Chemistry: 50
//     Name     Maths   Physics Chemistry     Total      Rank
//     John        90        80        70       240         1
//     Jane        80        70        60       210         2
//     Jack        70        60        50       180         3
