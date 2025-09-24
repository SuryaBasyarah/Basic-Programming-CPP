#include <iostream>
using namespace std;

int main()
{
    int angka[10] = {54, 23, 12, 56, 78, 50, 12, 89, 10, 12};
    int temp, j;
    for (int i = 1; i < 10; i++)
    {
        temp = angka[i];
        j = i-1;
        while ((temp < angka[j]) && (j >= 0))
        {
            angka[j+1] = angka[j];
            j = j-1;
        }
        angka[j+1] = temp;
    }

    for (int j = 0; j < 10; j++)
    {
        cout << angka[j] << " ";
    }
    return 0;
}