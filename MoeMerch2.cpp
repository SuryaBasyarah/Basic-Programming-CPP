// Daspro Kelompok 5 MoeMerch.kawa
// Surya Basyarah Putra 105222016
// Jimmi Fernandes Rahman 105221038
// Ariel Yosua Hasibuan 105222004
// Bambang Istijab 105222007
// Sofia Melati Bareut Runa 105222005

#include <iostream>
#include <fstream>
using namespace std;

string AllMoeMerch[20];
int AllMoeMerchPrice[20];

int Count[20] = {0};

int SisaSaldo, TambahSaldo, GenOpt, total = 0, AddOpt;
char BackOpt;
ofstream Payment;
void ShowMoePay()
{   
    ifstream saldo;
    string temp;
    int MoePay;
    saldo.open("Saldo.txt");
    getline(saldo, temp);
    MoePay = stoi(temp);
    SisaSaldo = MoePay;
    saldo.close();
}

void SisaMoePay()
{
    ofstream saldo2;
    
    if (GenOpt == 4 || BackOpt == 'n' || BackOpt == 'y')
    {
        saldo2.open("Saldo.txt");
        saldo2 << SisaSaldo;
        saldo2.close();
    }
}

void ClearData()
{
    remove("Struk.txt");
    for (int i = 0; i < 20; i++)
    {
        Count[i] = 0;
    }
    total = 0;
}

void MainMenu()
{
    system("cls");
    cout << "========================" << endl;
    cout << "       Moe Merch" << endl;
    cout << "========================" << endl;
    cout << "1. Isi Saldo Moepay" << endl;
    cout << "2. Cek Saldo MoePay" << endl;
    cout << "3. Beli Merchandise Fav" << endl;
    cout << "4. Keluar" << endl;
    cout << "========================" << endl;
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
    if (total > SisaSaldo)
    {
        ClearData();
    }
    else
    {
        SisaSaldo -= total;
        Payment.open ("Struk.txt");
        for (int i = 0; i < 20; i ++)
        {
            if (Count[i] >= 1)
            {
                Payment << AllMoeMerch[i] << "Rp. " << AllMoeMerchPrice[i] << " | " << "Q. " << Count[i] << " | " << "Total: Rp. " << (AllMoeMerchPrice[i] * Count[i]) << endl;           
            }   
        }
        Payment << "Total: " << total << endl;
        Payment << "Sisa Saldo: " << SisaSaldo;
        Payment.close();
    }
    
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

void ErrorPayment()
{
    
    if (SisaSaldo < total)
    {
        
        cout << "Saldo MoePay anda kurang (miskin detected), try again later." << endl;
        cout << "Kembali ke menu utama? (y/n): ";
        cin >> BackOpt;
    }
    else
    {   
        Struk();
        SisaMoePay();
        cout << "====================" << endl;
        cout << "   Thank you UwU" << endl;
        cout << "====================" << endl;
        cout << "Kembali ke menu utama? (y/n): ";
        cin >> BackOpt;
    }
}

void ShowAllMerch()
{
    ALLMERCH:
    system("cls");
    for (int i = 0; i < 20; i++)
    {
        cout << (i+1) << ". " << AllMoeMerch[i] << "Rp. " << AllMoeMerchPrice[i] << endl;
    }
    cout << "==========================================" << endl;
    cout << "21. Urutkan dari termahal" << endl;
    cout << "22. Sort by default" << endl;
    cout << "WARNING! ITEM RESET AFTER SORTED" << endl;
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
                    break;
                case 1:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[0] * Count[GenOpt-1];
                    break;
                case 2:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[1] * Count[GenOpt-1];
                    break;
                case 3:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[2] * Count[GenOpt-1];
                    break;
                case 4:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[3] * Count[GenOpt-1];
                    break;
                case 5:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[4] * Count[GenOpt-1];
                    break;
                case 6:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[5] * Count[GenOpt-1];
                    break;
                case 7:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[6] * Count[GenOpt-1];
                    break;
                case 8:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[7] * Count[GenOpt-1];
                    break;
                case 9:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[8] * Count[GenOpt-1];
                    break;
                case 10:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[9] * Count[GenOpt-1];
                    break;
                case 11:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[10] * Count[GenOpt-1];
                    break;
                case 12:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[11] * Count[GenOpt-1];
                    break;
                case 13:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[12] * Count[GenOpt-1];
                    break;
                case 14:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[13] * Count[GenOpt-1];
                    break;
                case 15:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[14] * Count[GenOpt-1];
                    break;
                case 16:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[15] * Count[GenOpt-1];
                    break;
                case 17:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[16] * Count[GenOpt-1];
                    break;
                case 18:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[17] * Count[GenOpt-1];
                    break;
                case 19:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[18] * Count[GenOpt-1];
                    break;
                case 20:
                    cout << "Jumlah: ";
                    cin >> Count[GenOpt-1];
                    total += AllMoeMerchPrice[19] * Count[GenOpt-1];
                    break;
                case 21:
                    AllSortedDsc();
                    ClearData();
                    goto ALLMERCH;
                    break;
                case 22:
                    DefaultFile();
                    ClearData();
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

void program()
{
    ShowMoePay();
    DefaultFile();
    MAINMENU:
    
    ClearData();
    MainMenu();

    cout << "Pilih Opsi: ";
    cin >> GenOpt;
    switch (GenOpt)
    {
    case 1:
        ISISALDO:
        IsiSaldo();
        SisaMoePay();
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
        SisaMoePay();
        if (BackOpt == 'y')
        {
            goto MAINMENU;
        }
        else if (BackOpt == 'n')
        {
            
            exit(0);
        }
    break;
    case 3:
        ShowAllMerch();
        if (BackOpt == 'y')
        {
            
            goto MAINMENU;
        }
        else if (BackOpt == 'n')
        {
            exit(0);
        }
    break;
    case 4:
        SisaMoePay();
    break;
    default:
        break;
    }
}

int main() {
    program();
}