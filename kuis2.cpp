#include <iostream>
#include <fstream>
using namespace std;
int array[5] = {94, 95, 74, 78, 20}, a, b;
int array2[2][3] = {{70,50,88},{79,65,90}};

void show()
{
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }
}

// int fun (int x = 0, int y = 0, int z)
// {  
//     return (x + y + z);
// }
int main()
{
    // cout << endl;
    // for (int i = 1; i < 5; i++)
    // {
    //     a = array[i];
    //     b = i;
    //     while (b > 0 && array[b-1] > a)
    //     {
    //         array[b] = array[b-1];
    //         b--;
    //     }
    //     array[b] = a;
    //     show();
    //     cout << endl;
    // }
    cout << array2[1][2];



//    cout << fun(10);


    

    return 0;
}