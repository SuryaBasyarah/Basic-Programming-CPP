#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char data[300];
    ifstream read;
    string kalimat;
    read.open ("identitas.txt");
    while (getline(read, kalimat))
    {
        cout << kalimat << endl;
    }
    
    read.close();
    
    return 0;
}