#include <iostream>
using namespace std;

int main()
{
    float angka, total = 0, rata2;
    int angka1;
    cout << "Masukkan jumlah angka yang ingin dihitung: ";
    cin >> angka1;
    cout << endl;
    for (int i = 1; i <= angka1; i++)
    {
        cout << "Masukkan bilangan ke-" << i << ": ";
        cin >> angka;
        total += angka;
    }
    cout << endl;
    rata2 = total / angka1;
    cout << "Rata-rata dari angka yang anda masukkan adalah " << rata2;
    return 0;
}