#include <iostream>
using namespace std;

int main()
{
    float BB, TB, BMI;
    cout << "Masukan tinggi badan anda (m): ";
    cin >> TB;
    cout << "Masukan berat badan anda (kg): ";
    cin >> BB;
    BMI = BB / (TB * TB);
    cout << "BMI: " << BMI << endl;
    if (BMI >= 18.5 && BMI <= 25)
    {
        cout << "BMI normal";
    }
    else
    {
        cout << "BMI tidak normal";
    }
    return 0;
}