#include <iostream>
using namespace std;

int main ()
{
    int i;
    int A = 1;
    int n;
    cout << "Input value: ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        A *= i;
    }
    cout << "Factorial of " << n << " is " << A;
    return 0;
}