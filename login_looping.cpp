#include <iostream>
using namespace std;


string us1, us2, pw1, pw2;
bool trylogin = true;
int main()
{
    cout << "Enter your username: ";
    cin >> us1;
    cout << "Enter your password: ";
    cin >> pw1;
    cout << endl;
        string answ;
        while (answ != "login" || answ != "exit")
        {
            cout << "Login or exit? ";
            cin >> answ;
            system("cls");
            if (answ == "login")
            {
                cout << "Enter your username: ";
                cin >> us2;
                cout << "Enter your password: ";
                cin >> pw2;
                cout << endl;
                while (us2 != us1 || pw2 != pw1)
                {
                    cout << "Wrong username or password! Try again.";
                    cout << "\n" << endl;
                    cout << "Enter your username: ";
                    cin >> us2;
                    cout << "Enter your password: ";
                    cin >> pw2;
                    cout << endl;
                }
                if (us2 == us1 && pw2 == pw1)
                {
                    cout << "Login succeed";
                    break;
                    bool trylogin = false;
                }
                break;
            }
            else if (answ == "exit")
            {
                cout << "Login failed";
            }
        break;
        }
    return 0;
}