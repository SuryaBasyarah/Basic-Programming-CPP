#include <iostream>
using namespace std;

int main()
{
    int JamAwal, JamAkhir, MenitAwal, MenitAkhir, DetikAwal, DetikAkhir, KodeWilayah;
    double Jam, Menit, Detik, Durasi, DurasiAkhir, DurasiAwal, Biaya;
    int i = 1;
    cout << "1. 021 untuk jakarta \n2. 0751 untuk padang \n3. 0737 untuk medan \n4. 0912 untuk balikpapan \n5. 0981 untuk ternate \nmasukan kode wilayah: ";
    cin >> KodeWilayah;
    cout << "masukan jam anda menelpon (dalam satuan 24 jam): ";
    cin >> JamAwal;
    cout << "masukan menit anda menelpon: ";
    cin >> MenitAwal;
    cout << "masukan detik anda menelpon: ";
    cin >> DetikAwal;
    cout << "masukan jam anda selesai menelpon (dalam satuan 24 jam): ";
    cin >> JamAkhir;
    cout << "masukan menit anda selesai menelpon: ";
    cin >> MenitAkhir;
    cout << "masukan detik anda selesai menelpon: ";
    cin >> DetikAkhir;
    
    void Durasi1();
    {
        DurasiAkhir = JamAkhir * 3600 + MenitAkhir * 60 + DetikAkhir; //3 * 3600 + 0 * 60 + 0
        DurasiAwal = JamAwal * 3600 + MenitAwal * 60 + DetikAwal; //1 * 3600 + 0 * 60 + 0
        if (DurasiAkhir < DurasiAwal)
        {
            Durasi = 86400 - DurasiAwal + DurasiAkhir; //tidak berlaku karena durasi akhir > durasi awal
        }
        else
        {
            Durasi = DurasiAkhir - DurasiAwal; //durasi = 10800 - 3600 = 7200
        }
    }
        switch (KodeWilayah)
        {
            case 1:
                void Durasi1();
                Biaya = (Durasi / 60) * 150; //biaya = (7200 / 60) * 150 = 18000
                cout << "Biaya yang harus anda bayar adalah Rp." << Biaya; //print "18000"
                break;
            case 2:
                void Durasi1();
                Biaya = (Durasi / 30) * 250;
                cout << "Biaya yang harus anda bayar adalah Rp." << Biaya;
                break;
            case 3:
                void Durasi1();
                Biaya = (Durasi / 25) * 375;
                cout << "Biaya yang harus anda bayar adalah Rp." << Biaya;
                break;
            case 4:
                void Durasi1();
                Biaya = (Durasi / 20) * 415;
                cout << "Biaya yang harus anda bayar adalah Rp." << Biaya;
                break;
            case 5:
                void Durasi1();
                Biaya = (Durasi / 17) * 510;
                cout << "Biaya yang harus anda bayar adalah Rp." << Biaya;
                break;
            default:
                cout << "pilihan salah, coba lagi.";
                break;
        }
    return 0;
}