#include <iostream>
#include <string>
using namespace std;

int z;
string sntnc;
#define lngth 10000;
void Code(string &sntnc, int N)
{
    for (int i = 0; i < N; i++) 
    {
        cout << sntnc[i] << " ";
    }
}
void ASCIICode(string &sntnc, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << int(sntnc[i] + z) << " ";
    }
}
void RealMeaning(string &sntnc, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << char(sntnc[i] + z) << " ";
    }
}

int main()
{
    cout << "Input sentences to convert into code: ";
    getline (cin, sntnc);
    cout << "Code increase by: ";
    cin >> z;
    int N = sntnc.length();
    Code(sntnc, N);
    cout << endl;
    ASCIICode(sntnc, N);
    cout << endl;
    RealMeaning(sntnc, N);
    return 0;
}