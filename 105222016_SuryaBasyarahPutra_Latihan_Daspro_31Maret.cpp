#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    float number, total = 0, ratarata;
    while (number != 00)
    {
        cout << "Masukkan angka ke-" << i << ": ";
        cin >> number;
        if (i == 1 && number == 00)
        {
            cout << "Tidak ada data yang dapat diolah";
        }
        total += number;
        i++;
    }
    if (i == 1)
    {
        i = i - 2;
        ratarata = total / i;
        cout << endl;
        cout << "Jumlah angka yang anda masukkan: " << i << endl;
        cout << "Total angka yang anda masukkan adalah: " << total << endl;
        cout << "Rata-rata angka yang anda masukkan adalah: " << ratarata;
    }
    return 0;
}