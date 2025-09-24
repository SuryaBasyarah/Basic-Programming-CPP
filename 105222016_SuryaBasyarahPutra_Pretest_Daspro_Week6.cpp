#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    float number, total = 0, ratarata;
    while (number != 0)
    {
        cout << "Masukkan angka ke-" << i << ": ";
        cin >> number;
        total += number;
        i++;
    }
    i = i - 2;
    ratarata = total / i;
    cout << endl;
    cout << "Jumlah angka yang anda masukkan: " << i << endl;
    cout << "Total angka yang anda masukkan adalah: " << total << endl;
    cout << "Rata-rata angka yang anda masukkan adalah: " << ratarata;
    return 0;
}