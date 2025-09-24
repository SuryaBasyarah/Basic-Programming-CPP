#include <iostream>
using namespace std;

int main()
{
    string produk[100];
    int stok[100];
    int jps;
    cout << "menambahkan produk dan stok: ";
    cin >> jps;
    produk[jps];
    stok[jps];
    for (int i = 0; i < jps; i++)
    {
        cout << "produk: ";
        cin >> produk[i];
        cout << "stok: ";
        cin >> stok[i];
    }
    int temp;
    string temp1;
    for (int k = 0; k < jps; k++)
    {
        for (int i = 0; i < jps; i++)
        {
            if(stok[i] > stok[i+1])
            {
                temp = stok[i+1];
                temp1 = produk[i+1];
                stok[i+1] = stok[i];
                produk[i+1] = produk[i];
                stok[i] = temp;
                produk[i] = temp1;
            }

        }
    }
    cout << endl;
    cout << "hasil sorting: " << endl;
    for (int j = 0; j < jps; j++)
    {
        cout << "produk: " << produk[j] << endl;
        cout << "stok: " << stok[j] << endl;
    }

    return 0;
}