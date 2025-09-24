#include <iostream>
using namespace std;

int main()
{
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