#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    while (a <= 10)
    {
        cout << a << endl;
        a++;
    }
    cout << endl;

    int b = 1;
    do
    {
        cout << b << endl;
        b++;
    } while (b <= 10);
    
    return 0;
}
//pada looping while diberikan kondisi terlebih dahulu kemudian di dalam while tersebut berisi kode yang ingin di-looping
//pada looping do-while diberikan syntax "do" kemudian isi yang akan di jalankan atau di-looping dan kondisi berada pada luar tanda kurung kurawal dengan syntax "while"