#include <iostream>
using namespace std;

int main () {
    int JenisPenjumlahan;
    int num1, num2;
    float sum; 
    int sum1;

    cout << "enter your first number: ";
    cin >> num1;
    cout << "enter your second number: ";
    cin >> num2;
    cout << "1: first + second \n2: first - second \n3: first * second \n4: first / second \n5: first div second \n6: first mod second \npick the operation: ";
    cin >> JenisPenjumlahan;

    switch (JenisPenjumlahan)
    {
        case 1:
            sum = num1 + num2;
            cout << "answer: " << sum;
            break;
        case 2:
            sum = num1 - num2;
            cout << "answer: " << sum;
            break;
        case 3:
            sum = num1 * num2;
            cout << "answer: " << sum;
            break;
        case 4:
            sum = num1 / num2;
            cout << "answer: " << sum;
            break;
        case 5:
            sum1 = num1 / num2;
            cout << "answer: " << sum1;
            break;
        case 6:
            sum1 = num1 % num2;
            cout << "answer: " << sum1;
            break;
        default:
            cout << "pick 1, 2, 3, 4, 5 or 6 only.";
            break;
    }
    return 0;
}