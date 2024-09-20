// Current time in GMT in the format HH:MM:SS

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t now = time(NULL);

    cout << "The current time in seconds from 1970 is: " << now << endl;

    int hours = (now / 3600) % 24;
    int minutes = (now / 60) % 60;
    int seconds = now % 60;

    cout << "The current time in GMT is: " << hours + 5 << ":" << minutes << ":" << seconds << endl;

    return 0;
}