#include <iostream>
using namespace std;

int main()
{
    int saldo = 1000000;
    string pin1, pin = "123456";
    int tariktunai;
    cout << "Nominal tarik tunai: ";
    cin >> tariktunai;
    cout << "Masukan pin: ";
    cin >> pin1;
    if (tariktunai <= saldo && pin1 == pin)
    {
        cout << "========================" << endl;
        cout << "Nominal tarik tunai: " << tariktunai << endl;
        saldo -= tariktunai;
        cout << "Sisa saldo: " << saldo;
    }
    else
    {
        cout << "========================" << endl;
        cout << "Transaksi gagal";
    }
    return 0;
}