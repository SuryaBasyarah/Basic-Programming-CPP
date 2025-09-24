#include <iostream>
using namespace std;

int main()
{
    int lngth, diff, i, num1, num2, num3, num4, num5, diff1, mult, lngth1, str, str1, lngth2, str2, diff2;
    cout << "Enter length: ";
    cin >> lngth;
    cout << "Enter multiply: ";
    cin >> mult;
    cout << "Starts from: ";
    cin >> str;

    num1 = str; //str = 1, num1 = 1
    cout << num1 << " "; //print num1
    for (i = 1; i < lngth; i++)
    {
        num1 = num1 * mult;  //1 = 1 * 3, 3 i = 1
                             //3 = 3 * 3, 9 i = 2
                             //9 = 9 * 3, 27 i = 3
                             //27 = 27 * 3, 81 i = 4
        cout << num1 << " ";
    }
    cout << "\n";
    cout << "============================================\n";
    cout << "Enter length: ";
    cin >> lngth1;
    cout << "Enter difference: ";
    cin >> diff1;
    cout << "Starts from: ";
    cin >> str1;

    num2 = str1;
    cout << num2 << " ";
    for (i = 1; i < lngth1; i++)
    {
        num2 = num2 + diff1;
        cout << num2 << " ";
    }
    cout << "\n";
    cout << "============================================\n";
    cout << "Enter length: ";
    cin >> lngth2;

    num3 = 1;
    num4 = 0;
    num5 = num3 + num4;
    for (i = 1; i <= lngth2; i++)
    {
        num5 = num3 + num4;
        num4 = num3;
        num3 = num5;
        cout << num5 << endl;
    }
    return 0;
}