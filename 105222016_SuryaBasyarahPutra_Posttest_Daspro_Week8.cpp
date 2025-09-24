#include <iostream>
using namespace std;

void hexa(int x)
{
    if (x > 1)
    {
        hexa(x / 16);
        int y = x % 16;
        if (y <= 9)
        {
            cout << y;
        }
        else if (y == 10)
            {
                cout << "A";
            }
            else if (y == 11)
            {
                cout << "B";
            }
            else if (y == 12)
            {
                cout << "C";
            }
            else if (y == 13)
            {
                cout << "D";
            }
            else if (y == 14)
            {
                cout << "E";
            }
            else if (y == 15)
            {
                cout << "F";
            }
            
    }
}

int main()
{
    int num;
    cout << "Input: ";
    cin >> num;
    hexa(num);
    return 0;
}