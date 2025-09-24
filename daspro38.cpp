#include <iostream>
using namespace std;

int fibonnaci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonnaci(n - 1) + fibonnaci(n - 2);
    }
}

int main()
{
    int x, y = 0;
    cout <<  "input: ";
    cin >> x;
    for (int i = 1; i <= x; i++)
    {
        cout << fibonnaci(i);
        y++;
        if (i == x)
        {
            break;
        }
        cout << ", ";
    }
    return 0;
}