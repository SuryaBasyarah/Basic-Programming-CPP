#include <iostream>
using namespace std;

int pangkat(int base, int power)
{
    
    if (power == 1)
    {
        return base;
    }
    else if (power == 0)
    {
        return 1;
    }
    else if (power >= 1)
    {
        return base * pangkat(base, power - 1);
    }
}

int main()
{
    int base, power, result;
    cout << "Base: ";
    cin >> base;
    cout << "Power: ";
    cin >> power;
    result = pangkat(base, power);
    cout << base << "^" << power << " = " << result;
    return 0;
}