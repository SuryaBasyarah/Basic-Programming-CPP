#include <iostream>
using namespace std;

int x, i, j, k;

int main()
{
    cout << "Enter perimeter: ";
    cin >> x;
    cout << "=============================================";
    cout << endl;
    for (i = 1; i <= x ;i++)
    {
        for (j = 1; j < i;j++)
        {
            cout << " ";
        }
        for (k = x; k >= i; k--)
        {
            cout << "A";
        }
    cout << endl;
    }
    cout << "=============================================";
    cout << endl;
    for (i = 1; i <= x ;i++)
    {
        for (j = x; j > i;j--)
        {
            cout << " ";
        }
        for (k = 1; k <= i; k++)
        {
            cout << "A";
        }
    cout << endl;
    }
    cout << "=============================================";
    cout << endl;
    for (i = 1; i <= x; i++)
    {
        for (j = x; j > i; j--)
        {
            cout << " ";
        }
        for (k = 1; k <= (2*i - 1); k++)
        {
            cout << "A";
        }
    cout << endl;
    }
    cout << "=============================================";
    cout << endl;
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (k = x; k >= (2*i - x); k--)
        {
            cout << "A";
        }
    cout << endl;
    }
    cout << "=============================================";
    cout << endl;
    for (i = 1; i <= x ;i++)
    {
        for (k = x; k >= i; k--)
        {
            cout << "A";
        }
    cout << endl;
    }
    cout << "=============================================";
    cout << endl;
    for (i = 1; i <= x ;i++)
    {
        for (k = 1; k <= i; k++)
        {
            cout << "A";
        }
    cout << endl;
    }
    cout << "=============================================";
    cout << endl;
    for (i = 1; i <= x; i++)
    {
        for (j = x; j > i; j--)
        {
            cout << " ";
        }
        for (k = 1; k <= (2*i - 1); k++)
        {
            cout << "A";
        }
    cout << endl;
    }
    for (i = 2; i <= x; i++)
    {
        for (j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (k = x; k >= (2*i - x); k--)
        {
            cout << "A";
        }
    cout << endl;
    }
    cout << "=============================================";
    cout << endl;
    return 0;
}