#include <iostream>
using namespace std;

int main()
{
    char karakter[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter any char: ";
        cin >> karakter[i];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << karakter[i] << " ";
    }
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (karakter[i] == 'A')
        {
            count++;
        }
    }
    cout << endl;
    cout << "Total of \"A\" is: ";
    cout << count;
    return 0;
}
//surya basyarah