#include <iostream>
using namespace std;

int main()
{
    string member;
    int poin1, poin2, poin3, poin4, poin5;
    float cashback = 1, diskon = 1;
    cout << "member (yes/no): ";
    cin >> member;
    cout << "cekpoin 1: ";
    cin >> poin1;
    cout << "cekpoin 2: ";
    cin >> poin2;
    cout << "cekpoin 3: ";
    cin >> poin3;
    cout << "cekpoin 4: ";
    cin >> poin4;
    cout << "cekpoin 5: ";
    cin >> poin5;

    void cashback1();
    {
        cashback = 3.1 * (poin1 + poin2 + poin3);
    }
    void diskon1();
    {
        diskon = 1.7 * (poin3 + poin4 + poin5);
    }

    if ((poin1 % 2 == 0) && (poin2 % 2 == 0) && (poin3 % 2 == 0) && (poin4 % 2 == 0) && (poin5 % 2 == 0))
    {
        void cashback1();
        if (member == "yes")
        {
            cashback = (15/100) * cashback;
            diskon = (15/100) * diskon;
        }
        diskon = 0;
    }
    else if ((poin1 % 2 == 1) && (poin2 % 2 == 1) && (poin3 % 2 == 1) && (poin4 % 2 == 1) && (poin5 % 2 == 1))
    {
        void diskon1();
        if (member == "yes")
        {
            cashback = (15/100) * cashback;
            diskon = (15/100) * diskon;
        }
        cashback = 0;
    }
    else
    {
        void cashback1();
        void diskon1();
    }

    cout << "cashback: " << cashback << endl;
    cout << "diskon: " << diskon;


    return 0;
}