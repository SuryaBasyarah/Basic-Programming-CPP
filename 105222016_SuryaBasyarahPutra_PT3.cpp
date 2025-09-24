#include <iostream>
#include <vector>
using namespace std;

vector<string> nama_hotel;
vector<string>::iterator I;

void input()
{
    while(true)
    {
        string input;
        cout << "Input: ";
        cin >> input;
        if (input == "stop")
        {
            break;
        }
        nama_hotel.push_back(input);
    }
}

void showall(vector<string> READ)
{
    for (I = READ.begin(); I != READ.end(); I++)
    {
        cout << *I << endl;
    }
}

void adding()
{
    string add;
    int search;
    cout << "Add at: ";
    cin >> search;
    cout << "Enter place: ";
    cin >> add;

    nama_hotel.insert(nama_hotel.begin() + search - 1, add);
}

int main()
{
    input();
    cout << endl;
    showall(nama_hotel);
    cout << endl;
    adding();
    showall(nama_hotel);
    
    return 0;
}