#include <iostream>
using namespace std;

int main()
{
    int array[4] = {10, 50, 12, 100};
    int temp;
    int diff[3];
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            if(array[i] > array[i+1])
            {
                temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        diff[j] = array[j] - array[j+1];
        cout << diff[j] << " ";
    }
    cout << endl;
    int f = 0;
    cout << array[f] << " and " << array[f+1];
    return 0;
}