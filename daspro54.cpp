#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string barang[3] = {"Teh Botol", "Teh Gelas", "Teh Kotak"};
    int harga[3] = {4000, 1000, 5000};
    int count[3] = {0, 0, 0};
    int total = 0;
    string input;
    cout << "1. Teh Botol" << endl;
    cout << "2. Teh Gelas" << endl;
    cout << "3. Teh Kotak" << endl;
    do
    {
        cout << "Pilih barang: ";
        cin >> input;
        if (input == "1")
        {
            count[0]++;
            total+=harga[0];
        }
        else if (input == "2")
        {
            count[1]++;
            total+=harga[1];
        }
        else if (input == "3")
        {
            count[2]++;
            total+=harga[2];
        }
    } while (input != "ok");
    
    ofstream tagihan;
    tagihan.open ("tagihan.txt", ios::app);
    cout << endl;
    tagihan << "Teh Botol\t" << count[0] << endl;
    tagihan << "Teh Gelas\t" << count[1] << endl;
    tagihan << "Teh Kotak\t" << count[2] << endl;
    tagihan << "Total:\t" << total;
    tagihan.close();

    return 0;
}