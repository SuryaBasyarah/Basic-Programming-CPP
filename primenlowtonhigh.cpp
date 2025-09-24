#include<iostream>
using namespace std;
int main()
{
    int HighNum, LowNum, i, j;
    bool prime = true;
    cout << "Enter two number from low number to high number.";
    cout << "\nEnter the starting number cannot 0 and 1 (low number): ";
    cin >> LowNum;
    cout << "Enter the ending number (high number): ";
    cin >> HighNum;
    cout << "\nPrime numbers between " << LowNum <<" and " << HighNum << " are:\n";
    
    for (i = LowNum; i < HighNum; ++i)
    {
        prime = true;
        if (LowNum == 0 || LowNum == 1)
        {
            prime = false;
            break;
        }
        for (j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            cout << i << " ";
        }
    }
    return 0;

}