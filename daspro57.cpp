#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    char oldname[] = "identitas.txt";
    char newname[] = "identitasku.txt";
    if(rename(oldname,newname) != 0)
    {
        perror("Error rename file");
    }
    else
    {
        cout << "File renamed";
    }
    return 0;
}