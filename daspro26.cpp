#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    while (i < 10)
    {
        cout << i << endl;
        i++;
        if (i == 4)
        {
            break;
        }
    }
    cout << endl;
    i = 0;
    while (i < 10)
    {
        if (i == 4)
        {
            i++;
            continue;
        }
        cout << i << endl;
        i++;
    }
    cout << endl;
    int a = 10;
    loop:do
    {
        if (a == 15)
        {
            a++;
            goto loop;
        }
        cout << a << endl;
        a++;
    } while (a < 20);
    cout << endl;

    return 0;
}