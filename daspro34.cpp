#include <iostream>
using namespace std;

void naik_turun(int &penaikan, int &penurunan, int nilai, int jumlah)
{
    penaikan = nilai + jumlah;
    penurunan = nilai - jumlah;
}

int main()
{
    int hasilnaik, hasilturun;
    naik_turun(hasilnaik, hasilturun, 10, 5);
    cout << "Hasil naik: " << hasilnaik << endl;
    cout << "Hasil turun: " << hasilturun;

    return 0;
}