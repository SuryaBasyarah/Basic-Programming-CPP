#include <iostream>
using namespace std;

int main() {
	int x;
	cout << "your score: ";
	cin >> x;
	if (x <= 50) {
		cout << "D";
	} else if (x <= 60) {
		cout << "C";
	} else if (x <= 70) {
		cout << "B";
	} else if (x <= 80) {
		cout << "A";
	} else {
		cout << "S";
	}
	return 0;
}

