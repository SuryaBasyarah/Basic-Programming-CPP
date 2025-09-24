#include <iostream>

using namespace std;

int top = -1;

    char PEZ[10] = {'K', 'K', 'H', 'M', 'K', 'H', 'K', 'M', 'M', 'H'};
    char PEZWOYELLOW[10];
    char tempPEZ[10];

void withoutyellow()
{
    for (int i = 0; i < 10; i++)
    {
        
        if (tempPEZ[i] != 'K')
        {
            top++;
            PEZWOYELLOW[top] = tempPEZ[i];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << PEZWOYELLOW[i] << " ";
    }
}

void yellowonly()
{
    for (int i = 0; i < 10; i++)
    {
        if (tempPEZ[i] != 'M' && tempPEZ[i] != 'H')
        {
            top++;
            PEZ[top] = tempPEZ[i];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << PEZ[i] << " ";
    }
}

int main()
{
    system("cls");
    for (int i = 0; i < 10; i++)
    {
        tempPEZ[i] = PEZ[i];
        PEZ[i] = '\0';
    }

    int opt;
    cout << "1. without yellow" << endl;
    cout << "2. yellow only" << endl;
    cout << "opsi: ";
    cin >> opt;

    if (opt == 1)
    {
        withoutyellow();
    }
    else if (opt == 2)
    {
        yellowonly();
    }
    

    return 0;
}