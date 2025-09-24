#include <iostream>
using namespace std;

int main()
{
    int tipe, total, i, tipe1;
    int buku = 0;
    int harga = 0;
    cout << "Tipe pembeli: \n1. Individual \n2. Distributor \n";
    cin >> tipe;
    cout << "1. Masukan harga buku \n2. selesai \n";
    cin >> tipe1;
    if (tipe1 == 1)
    {
    for (i = 0; i++)
    {
        cin >> harga;
        total = total + harga;
    }
    }
    else
    {
        cout << total;
    }
    return 0;
}