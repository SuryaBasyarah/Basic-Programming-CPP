#include <iostream>
using namespace std;

void binary(int x)
{
    if (x > 1)
    {
        binary(x / 2);
        cout << x % 2;
    }
    else if (x == 0)
    {
        cout << "0";
    }
    else
    {
        cout << "1";
    }
    
}

int main()
{
    int num;
    cout << "num: ";
    cin >> num;
    binary(num);
    return 0;
}