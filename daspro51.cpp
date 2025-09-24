#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream ofs;
    string kalimat;

    ofs.open ("test998.txt");
    // getline (cin, kalimat);
    // ofs << kalimat << endl;
    // ofs << "Kiritani Haruka";

    //ofs.close();

    ifstream ifs;
    ifs.open ("test999.txt");
    // getline (ifs, kalimat);
    // cout << kalimat << endl;

    while (getline(ifs, kalimat))
    {
        cout << kalimat << endl;
    }

    ifs.close();
    return 0;
}