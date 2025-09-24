#include <iostream>
using namespace std;

int main(){
    int x;
    int i = 0;
    system ("cls");
    cout << "you must choose one from two choices below: \n1. i wanna be your gf \n2. i don't wanna be your gf \nmy choice: ";
    cin >> x;

    switch (x)
    {
    case (1):
        system ("cls");
        cout << "thanks! i appreciate it!";
        break;
    case (2):
        system ("cls");
        cout << "you must choose \"1\", pick the choices: ";
        cin >> x;
        if (x != 1)
        {
            do
            {
                system ("cls");
                cout << "you can't do that. \ntype \"1\". \n";
                i++;
                cin >> x;
            } 
            while (x != 1);
                system ("cls");
                cout << "that's what i expected.";
                break;
        }
        else
        {
            system ("cls");
            cout << "that's what i expected.";
            break;
        }    
    default:
        system ("cls");
        cout << "you can only choose 1 or 2, try again.";
        break;
    }
    return 0;
}