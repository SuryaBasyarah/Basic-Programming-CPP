#include <iostream>
using namespace std;

int main()
{
    float suhu;
    cout << "Masukan suhu: ";
    cin >> suhu;
    if (suhu <= 0)
    {
        cout << "Beku";
    }
    return 0;
}