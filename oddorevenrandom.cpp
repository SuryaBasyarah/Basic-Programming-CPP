#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int a;
    string answ;
    do 
    {
        system ("cls");
        a = rand() % 1000;
        cout << a << endl;
            if (a % 2 == 0) 
            {
                cout << a << " is even number." << endl;
            } 
            else if (a % 2 == 1) 
            {
                cout << a << " is odd number." << endl;
            } 
            else 
            {
                cout << a << " is zero.;" << endl;
            }
        cout << "Wanna generate again? (yes / no): ";
        cin >> answ;
    } 
    while (answ == "yes");
        system ("cls");
        cout << "Program end.";
    return 0; 
}