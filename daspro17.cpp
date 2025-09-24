#include <iostream>
using namespace std;

int main()
{
    int angka;
    cout << "Masukan angka akhir: ";
    cin >> angka;
    for (int i = 2; i <= angka; i += 2)
    {
        cout << i << endl;
    }
    return 0;
}