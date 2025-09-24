#include <iostream>
using namespace std;

int main()
{
    int choice; 
    float angka1, angka2, total;
    while (true)
    {
        system("cls");
        cout << "Kalkulator" << endl;
        cout << "1. Penjumlahan" << endl;
        cout << "2. Pengurangan" << endl;
        cout << "3. Perkalian" << endl;
        cout << "4. Pembagian" << endl;
        cout << "Masukkan pilihan anda (0 untuk keluar): ";
        cin >> choice;
        if (choice == 0 || choice < 0 || choice > 4)
        {
            break;
        }
        cout << endl;
        cout << "Masukkan angka pertama: ";
        cin >> angka1;
        cout << "Masukkan angka kedua: ";
        cin >> angka2;
        switch(choice)
        {
            case 1:
            total = angka1 + angka2;
            cout << "Total: " << total << endl;
            system("PAUSE");
            break;
            case 2:
            total = angka1 - angka2;
            cout << "Total: " << total << endl;
            system("PAUSE");
            break;
            case 3:
            total = angka1 * angka2;
            cout << "Total: " << total << endl;
            system("PAUSE");
            break;
            case 4:
            if (angka2 == 0)
            {
                cerr << "Error" << endl;
                system("PAUSE");
            }
            else
            {
                total = angka1 / angka2;
                cout << "Total: " << total << endl;
                system("PAUSE");
            }
            break;
            default:
            break;
        }
    }
    
    return 0;
}