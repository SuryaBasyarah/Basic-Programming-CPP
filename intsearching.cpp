#include <iostream>
using namespace std;

int main()
{
    int array[5] = {10, 50, 12, 30, 15};
    int temp;
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            if(array[i] > array[i+1])
            {
                temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << endl;
    }
    int x = 30;
    int first = 0, last = 4;
    int med = (first + last) / 2;
    while (first <= last)
    {
        if (array[med] < x)
        {
            first = med+1;
        }
        else if (array[med] == x)
        {
            cout << x << " found at " << (med) << endl;
            break;
        }
        else
        {
            last = med-1;
        }
        med = (first + last) / 2;
    }
    if (first > last)
    {
        cout << x << " is not found" << endl;
    }

    return 0;
}