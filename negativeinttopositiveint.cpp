#include <iostream>
using namespace std;

int main()
{
    int lngth, diff, i, num1, mult, str;
    cout << "Enter length: ";
    cin >> lngth;
    cout << "Enter multiply: ";
    cin >> mult;
    cout << "Starts from: ";
    cin >> str;

    num1 = str;
    cout << num1 << " ";
    for (i = 1; i < lngth; i++)
    {
        if (str < 0)
        {
            if (num1 < 0)
            {
                num1 = num1 / mult;
                cout << num1 << " ";
            }
            else if (num1 == 0)
            {
                num1 = num1 + mult;
                cout << num1 << " ";
            }
            else if (num1 > 0)
            {
                num1 = num1 * mult;
                cout << num1 << " ";
            }
        }
        else if (str > 0)
        {
            num1 = num1 * mult;
            cout << num1 << " ";
        }
    }
    cout << "\n";
}