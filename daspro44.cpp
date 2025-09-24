#include <iostream>
using namespace std;

int main()
{
    string pesan;
    getline (cin, pesan, ' ');
    for(int i = 0; i < pesan.length(); i++)
        cout << (int) pesan[i] << " ";
    cout << endl;
    for(int i = 0; i < pesan.length(); i++)
        cout << pesan[i] << " ";
    return 0;
}