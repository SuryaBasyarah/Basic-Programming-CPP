#include <iostream>
using namespace std;

int main()
{
    string wni = "indonesia", wni1;
    int usia1, usia = 18;
    string vaksinke1_1, vaksinke2_1, vaksinke1 = "sudah", vaksinke2 = "sudah";
    int pemberiandosis1, pemberiandosis = 6;
    cout << "Status kewarganegaraan (negara): ";
    cin >> wni1;
    cout << "Status vaksin ke 1 (sudah / belum): ";
    cin >> vaksinke1_1;
    cout << "Status vaksin ke 2 (sudah / belum): ";
    cin >> vaksinke2_1;
    cout << "Usia: ";
    cin >> usia1;
    cout << "Jarak pemberian dosis ke 2 (bulan): ";
    cin >> pemberiandosis1;
    if (wni1 == wni && vaksinke1_1 == vaksinke1 && vaksinke2_1 == vaksinke2 && usia1 >= usia && pemberiandosis1 >= pemberiandosis)
    {
        cout << "============================================" << endl;
        cout << "Anda diperbolehkan vaksin booster";
    }
    else
    {
        cout << "============================================" << endl;
        cout << "Anda tidak diperbolehkan vaksin booster";
    }

    return 0;
}