#include <iostream>
using namespace std;

int main()
{
    int temp;
    int arr[9] = {1,0,5,2,2,2,0,1,6};
    
    for (int k = 0; k < 9; k++)
    {
        for (int i = 0; i < 9; i++)
        {
            if(arr[i] > arr[i+1])
            {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for (int j = 0; j < 9; j++)
    {
        cout << arr[j] << " ";
    }
    return 0;
}
//surya basyarah
//105222016