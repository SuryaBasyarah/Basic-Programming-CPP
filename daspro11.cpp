#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    if (a > b && a > c)
    {
        cout << "a is the biggest";
    }
    else if (b > a && b > c)
    {
        cout << "b is the biggest";
    }
    else if (c > a && c > b)
    {
        cout << "c is the biggest";
    }
    else
    {
        cout << "all number are the same";
    }
    return 0;
}