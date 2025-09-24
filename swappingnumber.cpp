#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    int c;
    cout << "pick \"a\" integer: ";
    cin >> a;
    cout << "pick \"b\" integer: ";
    cin >> b;
    c = a; 
    a = b; 
    b = c;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}