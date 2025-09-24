#include <iostream>
using namespace std;

int main()
{
    cout << "Tek kotek kotek kotek, anak ayam turun berkotek" << endl;
    cout << "Tek kotek kotek kotek, anak ayam turun berkotek" << endl;
    cout << endl;
    int ayam = 5;
    while (ayam > 1)
    {
        cout << "Anak ayam turunlah " << ayam << endl;
        ayam--;
        cout << "Mati satu tinggallah " << ayam << endl;
        cout << endl;
        if (ayam == 1)
        {
            cout << "Anak ayam turunlah " << ayam << endl;
            cout << "Mati satu tinggal induknya" << endl;
            cout << endl;
        }
    }
    cout << "Tek kotek kotek kotek, anak ayam turun berkotek" << endl;
    cout << "Tek kotek kotek kotek, anak ayam turun berkotek" << endl;
    return 0;
}