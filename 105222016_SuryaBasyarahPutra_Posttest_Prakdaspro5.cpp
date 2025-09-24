#include <iostream>
using namespace std;

int main()
{
    int angka;
    for (int i = 1; i <= 10; i++)
    {
        if (i == 1)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka++;
            }
        cout << endl;
        }
    
        if (i == 2)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka+=2;
            }
        cout << endl;
        }
        if (i == 3)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka+=3;
            }cout << endl;
        }
        if (i == 4)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka+=4;
            }cout << endl;
        }
        if (i == 5)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka+=5;
            }cout << endl;
        }
        if (i == 6)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka+=6;
            }cout << endl;
        }
        if (i == 7)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka+=7;
            }cout << endl;
        }
        if (i == 8)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka+=8;
            }cout << endl;
        }
        if (i == 9)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka+=9;
            }cout << endl;
        }
        if (i == 10)
        {
            cout << "Kelipatan ke-" << i << ": ";
            angka = i;
            while (angka <= i * 10)
            {
                cout << angka << " ";
                angka+=10;
            }
        }
    }

    return 0;
}