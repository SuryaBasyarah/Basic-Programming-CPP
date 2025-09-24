#include <iostream>
using namespace std;

int a(int x, int y);
int b(int z);
int c(int x, int y, int z);

int main()
{
    int x, y;
    x = 1;
    y = x + 1;
    cout << c(x, y+3, x+y) << endl;
    return 0;

}

int a(int x, int y)
{
    x++;
    return (x + y);
}

int b(int z)
{
    int prod = a(z, z);
    cout << z << "  " << prod << endl;
}

int c(int x, int y, int z)
{
    int total = x + y + z;
    cout << total;
    int square = b(total) * 2;
    cout << square;
    return (square);

}