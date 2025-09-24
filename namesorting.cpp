#include <iostream>
using namespace std;

int main()
{
    string name[10] = {"Hutao", "Herta", "Takina", "Ayaka", 
                       "Illyasviel", "Chloe", "Mafuyu", 
                       "Himeko", "Matsuri", "Haruka"};
    int nameascii[10];
    int temp;
    string temp1;
    //sorting istri
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
    //looking for waifu (ayang virtual)
    string waifu;
    int numwaifu;
    cout << "Looking for your waifu? ";
    cin >> waifu;
    int start;
    numwaifu = (int) waifu[0];
    for (start = 0; start <= numwaifu; start++)
    {
        if (nameascii[start] == numwaifu)
        {
            break;
        }
    }
    int length = 10;
    int status = 0;
    for (int i = start; i < length; i++)
    {
        if (waifu == name[i])
        {
            status++;
            break;
        }
    }

    if (status == 0)
    {
        cout << "Waifu not found" << endl;
    }
    else
    {
        cout << "Waifu found" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (waifu == name[i])
            {
                cout << "at " << i << " member " << (i+1) << endl;
            }
        }
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << name[i] << endl;
    }
    return 0;
}