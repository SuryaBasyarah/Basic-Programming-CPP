#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Masukan angka: ";
    cin >> x;
    if (x > 0)
    {
        cout << x << " adalah bilangan positif";
    }
    else
    {
        cout << x << " adalah bilangan negatif";
    }
    return 0;
}