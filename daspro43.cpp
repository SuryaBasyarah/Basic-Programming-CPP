#include <iostream>
using namespace std;

string sntnc;
#define lngth 10000;
void ASCIICode(string &sntnc, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << int(sntnc[i]) << " ";
    }
}
void RealMeaning(string &sntnc, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << char(sntnc[i]) << " ";
    }
}

int main()
{
    cout << "Input sentences to convert into code: ";
    getline (cin, sntnc);
    int N = sntnc.length();
    cout << endl;
    RealMeaning(sntnc, N);
    cout << endl;
    ASCIICode(sntnc, N);
    cout << endl;    
    return 0;
}