#include <iostream>
using namespace std;

int main() {
	string a = "BMW S1000RR";
	string b = "PANIGALE V4R";
	string c = "NINJA H2";
	string d = "NO BIKE";
	int x;
	cout << "your height: ";
	cin >> x;
		if (x > 170)
		{
		cout << "Your Recommend bike is " << b;
		}
		else if (x > 160)
		{
		cout << "Your Recommend bike is " << a;
		}
		else if (x > 150)
		{
		cout << "Your Recommend bike is " << c;
		}
		else
		{
		cout << d;
		}
		return 0;
}