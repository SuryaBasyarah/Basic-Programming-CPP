#include<iostream>
using namespace std;
int main()
{
    int HighNum, LowNum, i, j;
    bool prime = true;
    cout << "Enter two number from high number to low number.";
    cout << "\nEnter the starting number (high number): ";
    cin >> HighNum;
    cout << "Enter the ending number, cannot 0 (low number): ";
    cin >> LowNum;
    cout << "\nPrime numbers between " << HighNum <<" and " << LowNum << " are:\n";
    
    for (i = HighNum; i > LowNum; --i)
    {
        prime = true;
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

