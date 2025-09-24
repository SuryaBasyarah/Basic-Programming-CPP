#include <iostream>
using namespace std;

int main()
{
    string pin = "55555", pin1, choice1;
    int saldo = 1000000, choice, tariktunai;

    while (true)
    {
        ATM:
        do
        {  
        system("cls");
        cout << "Selamat datang di ATM Pertamina" << endl;
        cout << "Masukkan Pin anda: ";
        cin >> pin1;
        cout << endl;
        } while (pin != pin1);
        system("cls");
        cout << "Silahkan pilih transaksi anda" << endl;
        cout << "1. Periksa saldo" << endl;
        cout << "2. Tarik tunai" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukkan pilihan anda: ";
        cin >> choice;
        if (choice < 1 || choice > 2)
        {
            cout << "Terima Kasih." << endl;
            break;
        }
        cout << endl;
        switch(choice)
        {
            case 1:
            cout << "Sisa saldo anda: " << saldo << endl;
            cout << "Apakah anda ingin melakukan transaksi lagi? (y/n): ";
            cin >> choice1;
            if (choice1 == "y")
            {
                goto ATM;
            }
            else
            {
                cout << "Terima Kasih.";
                exit(0);
            }
            cout << endl;
            break;
            case 2:
            cout << "Jumlah tarik tunai: ";
            cin >> tariktunai;
            
            if (saldo >= tariktunai)
            {
            saldo -= tariktunai;
            cout << "Jumlah tunai yang anda tarik: " << tariktunai << endl;
            cout << "Sisa saldo: " << saldo << endl;
            cout << "Apakah anda ingin melakukan transaksi lagi? (y/n): ";
            cin >> choice1;
                if (choice1 == "y")
                {
                    goto ATM;
                }
                else
                {
                    cout << "Terima Kasih.";
                    exit(0);
                }
            cout << endl;
            }
            else
            {
                cout << "Saldo anda tidak mencukupi" << endl;
                cout << "Apakah anda ingin melakukan transaksi lagi? (y/n): ";
                cin >> choice1;
                if (choice1 == "y")
                {
                    goto ATM;
                }
                else
                {
                    exit(0);
                }
                cout << endl;
            }
            break;
            default:
            break;
        }
        
    }
    return 0;
}