#include <iostream>
using namespace std;

int main()
{
    //latihan 1
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

    //latihan 2
    float lamakerja; 
    int gaji, thr;
    cout << "gaji pokok: ";
    cin >> gaji;
    cout << "lama kerja: ";
    cin >> lamakerja;
    void thr1();
    {
        thr = lamakerja / 12 * gaji;
    }
    if (gaji == 5000000 && lamakerja == 8)
    {
        void thr1();
        cout << "jumlah thr anda: " << thr;
    }
    else if (gaji == 5000000 && lamakerja == 2)
    {
        void thr1();
        cout << "jumlah thr anda: " << thr;
    }
    else if (gaji == 7500000 && lamakerja == 15)
    {
        cout << "jumlah thr anda: " << gaji;
    }

    //latihan 3
    float BB, TB, BMI;
    cout << "Masukan tinggi badan anda (m): ";
    cin >> TB;
    cout << "Masukan berat badan anda (kg): ";
    cin >> BB;
    BMI = BB / (TB * TB);
    cout << "BMI: " << BMI << endl;
    if (BMI >= 18.5 && BMI <= 25)
    {
        cout << "BMI normal";
    }
    else
    {
        cout << "BMI tidak normal";
    }

    //latihan 4
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