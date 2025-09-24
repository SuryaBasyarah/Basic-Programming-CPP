#include <iostream>
#include <fstream>
using namespace std;

string barang[3];
int harga[3];

void showfile()
{
    ifstream barang_harga;
    string item, tempprice;
    int price, temp = 0, temp1 = 0;
    barang_harga.open("Harga.txt");
    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
        {
            getline(barang_harga, item);
            barang[temp] = item;
            temp++;
        }
        else
        {
            getline(barang_harga, tempprice);
            price = stoi(tempprice);
            harga[temp1] = price;
            temp1++;
        }
    }
}

int main()
{
    showfile();
    int count[3] = {0, 0, 0};
    int total = 0;
    string input;
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << ". " << barang[i] << " | Rp. " << harga[i] << endl;
    }
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
    
    ofstream tagihan, tehgelas, tehkotak, tehbotol;
    tagihan.open ("Tagihan.txt");
    cout << endl;
    tagihan << "Teh Botol\t" << count[0] << endl;
    tagihan << "Teh Gelas\t" << count[1] << endl;
    tagihan << "Teh Kotak\t" << count[2] << endl;
    tagihan << "Total:\t" << total;
    tagihan.close();
    return 0;
}