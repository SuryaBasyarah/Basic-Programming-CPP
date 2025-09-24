#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string kalimat;
    ifstream cahaya;

    cahaya.open("test998.txt");
    getline (cahaya,kalimat);
    
    while(getline(cahaya,kalimat))
    {
        cout << kalimat << endl;
    }

    cahaya.close();
    return 0;
}