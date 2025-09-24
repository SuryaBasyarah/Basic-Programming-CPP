#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter your NIM: ";
    cin >> num;
    for (int i = 105222000; i <= num; i++)
    {
        if (i < num)
        {
        cout << i << endl;
        }
        else if (i = num)
        {
        cout << "Your NIM is: " << num << endl;
        }
    }
    return 0;
}