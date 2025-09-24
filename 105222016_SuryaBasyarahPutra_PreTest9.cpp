#include <iostream>
using namespace std;


int main()
{
    int bilangan[10];
    int i, j, k, m;
    int larg, low;
    for(m = 0; m < 10; m++)
    {
        cout << "input angka: ";
        cin >> bilangan[m];
    }
    int temp = bilangan[0];
    for(i = 0; i < 10; i++)
    {
            if(temp<bilangan[i])
            {
                temp = bilangan[i];
                m = i;
                larg = m;
            }      
    }
    int temp1 = bilangan[0];
    for(i = 0; i < 10; i++)
    {
            if(temp1>bilangan[i])
            {
                temp1 = bilangan[i];
                k = i;
                low = k;
            }      
    }
    cout << "Array max: " << temp << " in index " << m << endl;
    cout << "Array min: " << temp1 << " in index " << k;
    return 0;
}