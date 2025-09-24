#include <iostream>
using namespace std;

int main()
{
    //latihan 1
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

    //latihan 2
    int hari, totaldenda, refday, textday, refdenda = 2000, textdenda = 1000, jenisbuku;

    cout << "1. Reference Book \n2. Text Book \n3. Keduanya \nJenis buku yang dipinjam: ";
    cin >> jenisbuku;
    switch(jenisbuku)
    {
        case 1:
            cout << "Keterlambatan untuk Reference Book (Hari): ";
            cin >> refday;
            totaldenda = refday * refdenda;
            cout << "Total denda: " << totaldenda;
            break;

        case 2:
            cout << "Keterlambatan untuk Text Book (Hari): ";
            cin >> textday;
            totaldenda = textday * textdenda;
            cout << "Total denda: " << totaldenda;
            break;

        case 3:
            cout << "Keterlambatan untuk Reference Book (Hari): ";
            cin >> refday;
            cout << "Keterlambatan untuk Text Book (Hari): ";
            cin >> textday;
            totaldenda = (refday * refdenda) + (textday * textdenda);
            cout << "Total denda: " << totaldenda;
            break;
        
        default:
            cout << "Pilihan salah";
            break;
    }

    //latihan 3
    int usia, penghasilanbulan, pengeluaranbulan, statusekonomi;
    string answ;
    cout << "Masukan usia anda: ";
    cin >> usia;
    if (usia > 19)
    {
        cout << "Apakah anda bekerja (y/n)? ";
        cin >> answ;
        if (answ == "y")
        {
            cout << "Masukan penghasilan anda perbulan: ";
            cin >> penghasilanbulan;
            cout << "Masukan Pengeluaran anda perbulan: ";
            cin >> pengeluaranbulan;
            statusekonomi = penghasilanbulan - pengeluaranbulan;
            if (statusekonomi < 200000)
            {
                cout << "Anda miskin";
            }
            else
            {
                cout << "Anda tidak miskin";
            }
        }
        else if (answ == "n")
        {
            cout << "Anda miskin";
        }
    }
    else
    {
        cout << "Apakah anda berstatus pelajar (y/n)? ";
        cin >> answ;
        if (answ == "y")
        {
            cout << "Anda tidak miskin";
        }
        else if (answ == "n")
        {
            cout << "Anda miskin";
        }

    }
    return 0;
}