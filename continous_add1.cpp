#include <iostream>
using namespace std;

int main()
{
    float total = 0;
    float price;
    string choice;
    cout << "add or total? ";
    cin >> choice;
    int item = 0;
    system("cls");
    while (choice == "add")
    {
        cout << "add price: ";
        cin >> price;
        total += price;
        cout << "add or total? ";
        cin >> choice;
        item++;
        system("cls");
    }
    if (choice == "total")
    {
        cout << "Total price: " << total << " USD";
        cout << endl;
        cout << "Total item you added: " << item;
    }
return 0;
}