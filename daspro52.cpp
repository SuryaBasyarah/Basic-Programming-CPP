#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream test997;
    string name[10] = {"ardi", "putri", "angel", "indra", "gita", "dion", "riski", "dinata", "yolla", "vebi"};
    int nameascii[10];
    int temp;
    string temp1;
    int st, nd = 0;
    for (int st = 0; st < 10; st++)
    {    
        (int) name[st][nd];
        nameascii[st] = name[st][nd];
    }
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            if(nameascii[i] > nameascii[i+1])
            {
                temp = nameascii[i+1];
                temp1 = name[i+1];
                nameascii[i+1] = nameascii[i];
                name[i+1] = name[i];
                nameascii[i] = temp;
                name[i] = temp1;
            }
        }
    }
    test997.open ("daftarnama.txt", ios::out);
    for (int k = 0; k < 10; k++)
    {
        test997 << name[k] << endl;
    }
    test997.close();

    return 0;
}