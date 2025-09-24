#include <iostream>
using namespace std;

int main()
{
    int posisi, min, temp;
    int angka[10] = {54, 23, 12, 56, 78, 50, 12, 89, 10, 12};
    for (int i = 0; i < 10; i++)
    {
        min = angka[i];
        posisi = i;
        for (int j = i+1; j < 10; j++)
        {
            if (min > angka[j])
            {
                min = angka[j];
                posisi = j;
            }
        }
        temp = angka[i];
        angka[i] = angka[posisi];
        angka[posisi] = temp;
    }
    for (int j = 0; j < 10; j++)
    {
        cout << angka[j] << " ";
    }
    return 0;
}