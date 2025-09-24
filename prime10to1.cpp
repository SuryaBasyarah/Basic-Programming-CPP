#include <iostream>
using namespace std;

int main(){
    int i, j;
    bool prime = true;
    cout << "\nPrime Numbers between 10 and 2 are: \n";
    
    for (i = 10; i > 1; --i)
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