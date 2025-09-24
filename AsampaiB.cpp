#include <iostream>
using namespace std;

int main()
{
    int a, b, i;
    cout << "nilai a: "; //1 + 2 + 3 + 4 + ... + 10
    cin >> a;
    cout << "nilai b: ";
    cin >> b;
    for (i = 0; a <= b; a++)
    {
        i+=a; //0 = 0 + 1
    }
    cout << i;
    return 0;
}