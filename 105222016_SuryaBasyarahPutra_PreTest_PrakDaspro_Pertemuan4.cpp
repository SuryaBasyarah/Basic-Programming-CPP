#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter the month number: ";
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "januari" << endl;
        break;
    case 2:
        cout << "februari" << endl;
        break;
    case 3:
        cout << "maret" << endl;
        break;
    case 4:
        cout << "april" << endl;
        break;
    case 5:
        cout << "mei" << endl;
        break;
    case 6:
        cout << "juni" << endl;
        break;
    case 7:
        cout << "juli" << endl;
        break;
    case 8:
        cout << "agustus" << endl;
        break;
    case 9:
        cout << "september" << endl;
        break;
    case 10:
        cout << "oktober" << endl;
        break;
    case 11:
        cout << "november" << endl;
        break;
    case 12:
        cout << "desember" << endl;
        break;
    default:
        cout << "there is only 12 months, try again." << endl;
        break;
    }
        return 0;
}