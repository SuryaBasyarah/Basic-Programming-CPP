#include <iostream>
using namespace std;

int sum(int num)
{
    if (num != 0)
        return num + sum(num - 1);
    else
        return num;
}

int main()
{
    int number, hasil;
    cin >> number;
    hasil = sum(number);
    cout << hasil;
    //5 + 4 + 3 + 2 + 1

    return 0;
}