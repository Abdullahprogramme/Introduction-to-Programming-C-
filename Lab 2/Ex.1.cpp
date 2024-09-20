// Euclidean distance

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2 = 0, y2 = 0;
    cout << "Enter the x coordinate of the first point: ";
    cin >> x1;
    cout << "Enter the y coordinate of the first point: ";
    cin >> y1;
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "The Euclidean distance between the two points is: " << distance << endl;
    return 0;
}