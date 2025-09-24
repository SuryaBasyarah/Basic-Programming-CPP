#include <iostream>
using namespace std;

int main()
{
    int fakt = 1, angka;
    cout << "Masukan angka yang ingin di-faktorialkan: ";
    cin >> angka;
    for (int i = 1; i <= angka; i++)
    {
        fakt *= i;
    }
    cout << "Factorial dari " << angka << " adalah " << fakt;
    return 0;
}