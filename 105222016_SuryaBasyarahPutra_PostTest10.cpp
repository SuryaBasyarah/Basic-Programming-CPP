#include <iostream>
using namespace std;

int matrix[5][3] = {133, 23, 10, 
                    145, 25, 14, 
                    127, 30, 8, 
                    143, 27, 12, 
                    137, 33, 11};
void pengunjung()
{
    int total, totalorang = 0;
    for(int i = 0; i < 5; i++)
    {
        total = 0;
        for(int j = 0; j < 3; j++)
        {
            total+=matrix[i][j];
        }
        cout << "hari ke " << (i+1) << " " << total << endl;
        totalorang+=total;
    }
}
void perkategori()
{
    int total, totalorang = 0;
    for(int j = 0; j < 3; j++)
    {
        total = 0;
        for(int i = 0; i < 5; i++)
        {
            total+=matrix[i][j];
        }
        cout << "kategori ke " << (j+1) << " " << total << endl;
        totalorang+=total;
    }
    cout << endl;
    cout << "total orang: " << totalorang;
}

int main()
{
    pengunjung();
    cout << endl;
    perkategori();
    
    return 0;
}