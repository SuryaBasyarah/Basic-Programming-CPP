#include <iostream>
using namespace std;

int main()
{
    int matrix[8][8] = {{1,2,4,6},{2,5,6,8}};
    string nama[2] = {"farhan", "beno"};
    cout << nama[0][5] << endl;
    cout << nama[1][2] << endl;
    string inputan[5];
    cout << sizeof(inputan) << endl;
    cout << sizeof(inputan[0]) << endl;
    int hitung = sizeof(inputan)/sizeof(inputan[0]);
    for (int i = 0; i < hitung; i++)
    {
        cout << "input: ";
        cin >> inputan[i];
    }
    cout << endl;
    for (int i = 0; i < hitung; i++)
    {
        cout << inputan[i] << endl;
    }
    return 0;
}