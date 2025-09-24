#include <iostream>
using namespace std;

int main()
{
    int array[10] = {54, 23, 12, 56, 78, 50, 12, 89, 10, 12};
    int temp;

    cout << "Dari terkecil: " << endl;
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 9; i++)
        {
            if(array[i] > array[i+1])
            {
                temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
            }
        }
    }
    for (int j = 0; j < 10; j++)
    {
        cout << array[j] << " ";
    }

    cout << endl;
    cout << "Dari terbesar: " << endl;
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 9; i++)
        {
            if(array[i] < array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
    for (int j = 0; j < 10; j++)
    {
        cout << array[j] << " ";
    }
    return 0;
}