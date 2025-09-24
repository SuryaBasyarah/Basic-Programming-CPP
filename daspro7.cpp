#include <iostream>
using namespace std;

int main()
{
    int transaksi, total, diskon;
    cout << "Masukan total transaksi: ";
    cin >> transaksi;
    if (transaksi >= 250000)
    {
        diskon = transaksi * 33 / 100;
        total = transaksi - diskon;
        cout << "total diskon: " << diskon << endl;
        cout << "total harga: " << total;
    }
    else
    {
        total = transaksi;
        cout << "total harga: " << total;
    }
    return 0;
}