#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string convert(int n) {
	static const unordered_map<int, string> mapping = {{0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}};
	if (n == 0) return "";
	return convert(n / 10) + mapping.at(n % 10) + " ";
}

int main() {
    cout << convert(123) << endl;
    return 0;
}