#include <iostream>
using namespace std;

void percobaan(int *arr)
{
    cout << &arr[0] << endl;
    arr[2] = 200;
}

int main()
{
    int *b, a, c;
    a = 100;
    c = 50;
    b = &c;
    cout << a << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << *b;
    cout << endl << endl;

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << arr[2] << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << &arr[i] << endl;
    }

    cout << endl;
    percobaan(arr);
    cout << arr[2] << endl;
    return 0;
}