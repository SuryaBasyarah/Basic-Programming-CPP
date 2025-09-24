#include <iostream>
#include <fstream>
using namespace std;


ifstream read;
string kalimat;
ofstream read1;
void identitas()
{
    read.open ("identitas.txt", ios::app);
    while (getline(read, kalimat))
    {
        cout << kalimat << endl;
    } 
    read.close();
}
int main()
{
    identitas();
    read1.open ("identitas.txt", ios::app);
    read1 << "\n11 Agustus 2004";
    read1.close();
    cout << endl;
    identitas();
    return 0;
}