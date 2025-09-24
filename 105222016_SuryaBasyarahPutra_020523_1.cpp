#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num != 1)
        return num * factorial(num - 1);
    else
        return num;
}

int main()
{
    int number;
    cout << "Masukkan angka: ";
    cin >> number;
    if (number == 0)
    {
        cout << "Faktorial dari " << number << " atau " << number << "! = 1";
    }
    else
    {
        cout << "Faktorial dari " << number << " atau " << number << "! = " << factorial(number);
    }
    return 0;
}