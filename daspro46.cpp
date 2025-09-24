#include <iostream>
using namespace std;

void percobaan1(int *arr)
{
    arr[2] = 200;
}

int main()
{
    //int *b, a;
    // a = 100;
    // b = &a;
    // a = 60;
    // cout << a << endl
    // cout << &a <<endl;
    // cout << b << endl;
    // cout << *b << endl;
    double arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << &arr[0] << endl;
    cout << &arr[1] << endl;
    cout << &arr[2] << endl;
    cout << &arr[3] << endl;
    cout << &arr[4] << endl;
    cout << &arr[5] << endl;
    cout << &arr[6] << endl;
    cout << &arr[7] << endl;
    cout << &arr[8] << endl;
    cout << &arr[9] << endl;
    cout << &arr[10] << endl;
    cout << sizeof(arr[0]) << endl;

    percobaan1(arr);
    cout << arr[2] << endl;
    int matriks[8][8] = {{1,2,4,6}},{2,5,6,8}};
    string nama[2] = {"farhan". "beno"};
    cout << nama[0][0] << endl;
    cout << nama[1][0] << endl;
}
