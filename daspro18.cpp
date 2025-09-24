#include <iostream>
using namespace std;

int main()
{
    int total = 0, angka;
    for (int i = 1; i <= 10; i++)
    {
        cout << i << ". Masukan angka: ";
        cin >> angka;
        total += angka;
    }
    cout << endl;

    cout << "total bilangan: " << total;
    
    return 0;
}