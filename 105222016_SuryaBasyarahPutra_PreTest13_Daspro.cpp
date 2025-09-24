#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int count = 0;
    ifstream file;
    string baris;
    file.open("info.txt");
    while (getline(file, baris))
    {
        count++;
    }
    file.close();
    cout << "total baris dalam file: " << count << endl;
    cout << "total baris dalam file (format exclude): " << count-1;
    return 0;
}