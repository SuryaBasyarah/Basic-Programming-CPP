#include <iostream>
#include <fstream>
using namespace std;

string WallScrollsItem[6], ActionFiguresItem[6], MousepadsItem[5], OthersItem[3];
int WallScrollsPrice[6], ActionFiguresPrice[6], MousepadsPrice[5], OthersPrice[3];
string SortWS[6], SortAF[6], SortMP[5], SortOth[3];
int SortWSP[6], SortAFP[6], SortMPP[5], SortOthP[3];


int CountWS[6] = {0}, CountAF[6], CountMP[5], CountOth[3] = {0};
int total = 0;
int TambahSaldo, SisaSaldo, OpsiMainMenu, OpsiCekSaldo, GenOpt, ActFig, WallScr, MPad, Oth;

char OpsiTambahSaldo;
// void sortedws()
// {
//     int st, nd = 0;
//     for (int st = 0; st < 10; st++)
//     {    
//         (int) name[st][nd];
//         nameascii[st] = name[st][nd];
//     }
//     for (int k = 0; k < 10; k++)
//     {
//         for (int i = 0; i < 10; i++)
//         {
//             if(nameascii[i] > nameascii[i+1])
//             {
//                 temp = nameascii[i+1];
//                 temp1 = name[i+1];
//                 nameascii[i+1] = nameascii[i];
//                 name[i+1] = name[i];
//                 nameascii[i] = temp;
//                 name[i] = temp1;
//             }
//         }
//     }

// }

void ShowActionFigureItemAndPrice()
{
    ifstream AF_Item;
    ifstream AF_Price;
    string item, tempprice;
    int price;
    AF_Item.open("ActionFigure.txt");
    AF_Price.open("ActionFigurePrice.txt");
    for(int i = 0; i < 6; i++)
    {
        getline(AF_Item, item);
        ActionFiguresItem[i] = item;
        getline(AF_Price, tempprice);
        int price = stoi(tempprice);
        ActionFiguresPrice[i] = price;
        cout << ActionFiguresItem[i] << "Rp. " << ActionFiguresPrice[i] << endl;
    }
    AF_Price.close();
    AF_Item.close();
}

void ShowWallScrollItemAndPrice()
{
    ifstream WS_Item;
    ifstream WS_Price;
    string item, tempprice;
    int price;
    WS_Item.open("WallScroll.txt");
    WS_Price.open("WallScrollPrice.txt");
    for(int i = 0; i < 6; i++)
    {
        getline(WS_Item, item);
        WallScrollsItem[i] = item;
        getline(WS_Price, tempprice);
        int price = stoi(tempprice);
        WallScrollsPrice[i] = price;
        cout << WallScrollsItem[i] << "Rp. " << WallScrollsPrice[i] << endl;
    }
    WS_Price.close();
    WS_Item.close();
}

void ShowMousepadItemAndPrice()
{
    ifstream MP_Item;
    ifstream MP_Price;
    string item, tempprice;
    int price;
    MP_Item.open("Mousepad.txt");
    MP_Price.open("MousepadPrice.txt");
    for(int i = 0; i < 5; i++)
    {
        getline(MP_Item, item);
        MousepadsItem[i] = item;
        getline(MP_Price, tempprice);
        int price = stoi(tempprice);
        MousepadsPrice[i] = price;
        cout << MousepadsItem[i] << "Rp. " << MousepadsPrice[i] << endl;
    }
    MP_Price.close();
    MP_Item.close();   
}

void ShowOthersAndPrice()
{
    ifstream OTH_Item;
    ifstream OTH_Price;
    string item, tempprice;
    int price;
    OTH_Item.open("Others.txt");
    OTH_Price.open("OthersPrice.txt");
    for(int i = 0; i < 3; i++)
    {
        getline(OTH_Item, item);
        OthersItem[i] = item;
        getline(OTH_Price, tempprice);
        int price = stoi(tempprice);
        OthersPrice[i] = price;
        cout << OthersItem[i] << "Rp. " << OthersPrice[i] << endl;
    }
    OTH_Price.close();
    OTH_Item.close();   
}

void CekSaldo()
{
    system("cls");
    cout << "=========================" << endl;
    cout << "  Sisa Saldo: " << SisaSaldo  << endl;
    cout << "=========================" << endl;
    cout << "Kembali? (y/n) : ";
    cin >> OpsiCekSaldo;
}

void IsiSaldo()
{
    CekSaldo();
    cout << "Tambahkan saldo? (y/n) : ";
    cin >> OpsiTambahSaldo;
}

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

void Merchandise()
{
    system("cls");
    cout << "======================" << endl;
    cout << "1. Action Figures" << endl;
    cout << "2. Wall Scrolls" << endl;
    cout << "3. Mousepad" << endl;
    cout << "4. Others" << endl;
    cout << "5. Vestia Zeta Bundle" << endl;
    cout << "6. Nyanners Bundle" << endl;
    cout << "7. Yuzu x Mei Bundle" << endl;
    cout << "======================" << endl;
    cout << "Pilih Opsi: ";
    cin >> GenOpt;
}

void MoeMerchKawaii()
{
    switch (GenOpt)
    {
    case 1:
        ShowActionFigureItemAndPrice();

        break;
    
    default:
        break;
    }
}

int main()
{

    return 0;
}