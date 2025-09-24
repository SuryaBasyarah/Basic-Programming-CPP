#include <iostream>
#include <fstream>
using namespace std;

string AllMoeMerch[20];
int AllMoeMerchPrice[20];

string sortedmerch[20];
int sortedprice[20];

int Count[20] = {0};

int SisaSaldo = 5000000, TambahSaldo, GenOpt, total = 0, KeepAdd, AddOpt;
char BackOpt;

void MainMenu()
{
    system("cls");
    cout << "======================" << endl;
    cout << "       Moe Merch" << endl;
    cout << "======================" << endl;
    cout << "1. Isi Saldo Moepay" << endl;
    cout << "2. Cek Saldo MoePay" << endl;
    cout << "3. Beli Merchandise Fav" << endl;
    cout << "======================" << endl;
}
void DefaultFile()
{
    ifstream Merch_Item;
    ifstream Merch_Price;
    string item, tempprice;
    int price;
    Merch_Item.open("MoeMerch.txt");
    Merch_Price.open("MoeMerchPrice.txt");
    for(int i = 0; i < 20; i++)
    {
        getline(Merch_Item, item);
        AllMoeMerch[i] = item;
        getline(Merch_Price, tempprice);
        int price = stoi(tempprice);
        AllMoeMerchPrice[i] = price;
    }
    Merch_Price.close();
    Merch_Item.close();
}

void Struk()
{
    ofstream Payment;
    Payment.open ("Struk.txt", ios::out);
    for (int i = 0; i < 20; i ++)
    {
        if (Count[i] >= 1)
        {
            Payment << AllMoeMerch[i] << "Rp. " << AllMoeMerchPrice[i] << " | " << "Q. " << Count[i] << " | " << (AllMoeMerchPrice[i] * Count[i]) << endl;           
        }   
    }
    Payment << "Total: " << total << endl;
    Payment << "Sisa Saldo: " << SisaSaldo;
    Payment.close();
}

void AllSortedDsc()
{
    int temp;
    string temp1;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (AllMoeMerchPrice[j] < AllMoeMerchPrice[j + 1])
            {
                temp = AllMoeMerchPrice[j];
                temp1 = AllMoeMerch[j];
                AllMoeMerchPrice[j] = AllMoeMerchPrice[j+1];
                AllMoeMerch[j] = AllMoeMerch[j+1];
                AllMoeMerchPrice[j+1] = temp;
                AllMoeMerch[j+1] = temp1;
            }
        }
    }
}

void AllSortedAsc()
{
    int temp2;
    string temp3;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (AllMoeMerchPrice[j + 1] < AllMoeMerchPrice[j])
            {
                temp2 = AllMoeMerchPrice[j+1];
                temp3 = AllMoeMerch[j+1];
                AllMoeMerchPrice[j+1] = AllMoeMerchPrice[j];
                AllMoeMerch[j+1] = AllMoeMerch[j];
                AllMoeMerchPrice[j] = temp2;
                AllMoeMerch[j] = temp3;
            }
        }
    }
}

void ErrorPayment()
{
    if (SisaSaldo < total)
    {
        cout << "Saldo MoePay anda kurang (miskin detected), try again later.";
        exit(0);
    }
    else
    {
        SisaSaldo -= total;
        cout << "====================" << endl;
        cout << "   Thank you UwU" << endl;
        cout << "====================" << endl;
    }
}

void ShowAllMerch()
{
    ALLMERCH:
    for (int i = 0; i < 20; i++)
    {
        cout << (i+1) << ". " << AllMoeMerch[i] << "Rp. " << AllMoeMerchPrice[i] << endl;
    }
    cout << "==========================================" << endl;
    cout << "21. Urutkan dari termurah" << endl;
    cout << "22. Urutkan dari termahal" << endl;
    cout << "23. Sort by default" << endl;
    cout << "==========================================" << endl;   
    while (GenOpt != 0)
            {
                cout << "Pilih Merchandise/opsi (0 untuk selesai): ";
                cin >> GenOpt;
                switch (GenOpt)
                {
                case 0:
                    system("cls");
                    ErrorPayment();
                    Struk();
                    exit(0);
                case 1:
                    Count[0]++;
                    total += AllMoeMerchPrice[0];
                    break;
                case 2:
                    Count[1]++;
                    total += AllMoeMerchPrice[1];
                    break;
                case 3:
                    Count[2]++;
                    total += AllMoeMerchPrice[2];
                    break;
                case 4:
                    Count[3]++;
                    total += AllMoeMerchPrice[3];
                    break;
                case 5:
                    Count[4]++;
                    total += AllMoeMerchPrice[4];
                    break;
                case 6:
                    Count[5]++;
                    total += AllMoeMerchPrice[5];
                    break;
                case 7:
                    Count[6]++;
                    total += AllMoeMerchPrice[6];
                    break;
                case 8:
                    Count[7]++;
                    total += AllMoeMerchPrice[7];
                    break;
                case 9:
                    Count[8]++;
                    total += AllMoeMerchPrice[8];
                    break;
                case 10:
                    Count[9]++;
                    total += AllMoeMerchPrice[9];
                    break;
                case 11:
                    Count[10]++;
                    total += AllMoeMerchPrice[10];
                    break;
                case 12:
                    Count[11]++;
                    total += AllMoeMerchPrice[11];
                    break;
                case 13:
                    Count[12]++;
                    total += AllMoeMerchPrice[12];
                    break;
                case 14:
                    Count[13]++;
                    total += AllMoeMerchPrice[13];
                    break;
                case 15:
                    Count[14]++;
                    total += AllMoeMerchPrice[14];
                    break;
                case 16:
                    Count[15]++;
                    total += AllMoeMerchPrice[15];
                    break;
                case 17:
                    Count[16]++;
                    total += AllMoeMerchPrice[16];
                    break;
                case 18:
                    Count[17]++;
                    total += AllMoeMerchPrice[17];
                    break;
                case 19:
                    Count[18]++;
                    total += AllMoeMerchPrice[18];
                    break;
                case 20:
                    Count[19]++;
                    total += AllMoeMerchPrice[19];
                    break;
                case 21:
                    AllSortedAsc();
                    goto ALLMERCH;
                    break;
                case 22:
                    AllSortedDsc();
                    goto ALLMERCH;
                    break;
                case 23:
                    DefaultFile();
                    goto ALLMERCH;
                    break;       
                default:
                    break;
                }
            }
}

void CekSaldo()
{
    system("cls");
    cout << "=========================" << endl;
    cout << "Sisa Saldo: " << SisaSaldo  << endl;
    cout << "=========================" << endl;
    cout << "Kembali? (y/n) : ";
    cin >> BackOpt;
}

void IsiSaldo()
{
    system("cls");
    cout << "=========================" << endl;
    cout << "Sisa Saldo: " << SisaSaldo  << endl;
    cout << "=========================" << endl;
    cout << "Tambahkan nominal saldo: ";
    cin >> AddOpt;
    SisaSaldo += AddOpt;
    cout << "Kembali? (y/n) : ";
    cin >> BackOpt;
}



int main()
{
    cout << "test" << endl;
    DefaultFile();
    MAINMENU:
    MainMenu();
    cout << "Pilih Opsi: ";
    cin >> GenOpt;
    switch (GenOpt)
    {
    case 1:
        ISISALDO:
        IsiSaldo();
        if (BackOpt == 'y')
        {
            goto MAINMENU;
        }
        else if (BackOpt == 'n')
        {
            goto ISISALDO;
        }
    break;
    case 2:
        CekSaldo();
        switch (BackOpt)
        {
        case 'y':
            goto MAINMENU;
            break;
        case 'n':
            exit(0);
            break;

        default:
            break;
        }
    break;
    case 3:
        ShowAllMerch();
        break;
    default:
        break;
    }
    return 0;
}