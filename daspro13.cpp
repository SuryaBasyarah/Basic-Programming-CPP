#include <iostream>
using namespace std;

int main()
{
    int hari, totaldenda, refday, textday, refdenda = 2000, textdenda = 1000, jenisbuku;

    cout << "1. Reference Book \n2. Text Book \n3. Keduanya \nJenis buku yang dipinjam: ";
    cin >> jenisbuku;
    switch(jenisbuku)
    {
        case 1:
            cout << "Keterlambatan untuk Reference Book (Hari): ";
            cin >> refday;
            totaldenda = refday * refdenda;
            cout << "Total denda: " << totaldenda;
            break;

        case 2:
            cout << "Keterlambatan untuk Text Book (Hari): ";
            cin >> textday;
            totaldenda = textday * textdenda;
            cout << "Total denda: " << totaldenda;
            break;

        case 3:
            cout << "Keterlambatan untuk Reference Book (Hari): ";
            cin >> refday;
            cout << "Keterlambatan untuk Text Book (Hari): ";
            cin >> textday;
            totaldenda = (refday * refdenda) + (textday * textdenda);
            cout << "Total denda: " << totaldenda;
            break;
        
        default:
            cout << "Pilihan salah";
            break;
    }  

    //cout << "Keterlambatan untuk Reference Book (Hari): ";
    //cin >> refday;
    //cout << "Keterlambatan untuk Text Book (Hari): ";
    //cin >> textday;
    //totaldenda = (refday * refdenda) + (textday * textdenda);
    //cout << "Total denda: " << totaldenda;
    return 0;
}