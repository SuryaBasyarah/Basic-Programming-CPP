#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef struct
{
    string name;
    string city;
}hotel_t;

typedef struct
{
    string NamaTipe;
    vector<hotel_t> DaftarHotel;
}Kelompok;

const int total = 4;
Kelompok NamaKelompok[total];

void JenisKelompok()
{
    NamaKelompok[0].NamaTipe = "Luxury";
    NamaKelompok[1].NamaTipe = "Premium";
    NamaKelompok[2].NamaTipe = "Midscale";
    NamaKelompok[3].NamaTipe = "Economy";
}

void TambahHotel(string tipe, string nama, string city)
{
    for (int i = 0; i < total; i++)
    {
        if(NamaKelompok[i].NamaTipe == tipe)
        {
            hotel_t Hotel;
            Hotel.name = nama;
            Hotel.city = city;
            NamaKelompok[i].DaftarHotel.push_back(Hotel);
            return;
        }
    }
}

void ShowAll()
{
    for (int i = 0; i < total; i++)
    {
        cout << NamaKelompok[i].NamaTipe << endl;
        for (int j = 0; j < NamaKelompok[j].NamaTipe.size(); j++)
        {
            cout << NamaKelompok[i].DaftarHotel[j].name << endl;
            cout << NamaKelompok[i].DaftarHotel[j].city << endl;
            cout << endl;
        }
    }
}

int main()
{
    JenisKelompok();
    TambahHotel("Luxury", "Raffles", "Jakarta");
    ShowAll();
    return 0;
}