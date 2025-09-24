#include <iostream>
using namespace std;

int main()
{
    int paket, penginapan, pesawat, penerbangan, makan, privcar, total, biayapesawat, biayapenginapan;
    cout << "Paket ke Mandalika Lombok \n1. Paket 2 hari \n2. Paket 3 hari \n3. Paket 4 hari \nPilih paket: ";
    cin >> paket;
    switch (paket)
    {
        case 1:
        cout << "Jenis Penginapan (perhari) \n1. Tradisional = Rp 800.000 \n2. Bintang 5 = Rp 2.000.000 \n3. Bintang 4 = Rp 1.500.000 \n4. Bintang 3 = Rp 1.000.000 \nPilih jenis penginapan: ";
        cin >> penginapan;
        makan = 50000 * 3 * 2;
        privcar = 1000000;
        switch (penginapan)
        {
            case 1:
            cout << "Jenis Penginapan (perhari) \n1. Tradisional = Rp 800.000 \n2. Bintang 5 = Rp 2.000.000 \n3. Bintang 4 = Rp 1.500.000 \n4. Bintang 3 = Rp 1.000.000 \nPilih jenis penginapan: ";
            cin >> penginapan;
            switch(penginapan)
            {
                case 1:
                biayapenginapan = 800000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                    break;

                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    
                    }
                }
                case 2:
                biayapenginapan = 2000000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                }
                case 3:
                biayapenginapan = 1500000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }

                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                }
                case 4:
                biayapenginapan = 1000000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }

                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                }
            }
        }
        case 2:
        cout << "Jenis Penginapan (perhari) \n1. Tradisional = Rp 800.000 \n2. Bintang 5 = Rp 2.000.000 \n3. Bintang 4 = Rp 1.500.000 \n4. Bintang 3 = Rp 1.000.000 \nPilih jenis penginapan: ";
        cin >> penginapan;
        makan = 50000 * 3 * 3;
        privcar = 1000000;
        switch (penginapan)
        {
            case 1:
            cout << "Jenis Penginapan (perhari) \n1. Tradisional = Rp 800.000 \n2. Bintang 5 = Rp 2.000.000 \n3. Bintang 4 = Rp 1.500.000 \n4. Bintang 3 = Rp 1.000.000 \nPilih jenis penginapan: ";
            cin >> penginapan;
            switch(penginapan)
            {
                case 1:
                biayapenginapan = 800000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;


                    }

                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    
                    }
                }
                case 2:
                biayapenginapan = 2000000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                }
                case 3:
                biayapenginapan = 1500000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;


                    }

                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                }
                case 4:
                biayapenginapan = 1000000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;


                    }

                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                }
            }
        }
        case 3:
        cout << "Jenis Penginapan (perhari) \n1. Tradisional = Rp 800.000 \n2. Bintang 5 = Rp 2.000.000 \n3. Bintang 4 = Rp 1.500.000 \n4. Bintang 3 = Rp 1.000.000 \nPilih jenis penginapan: ";
        cin >> penginapan;
        makan = 50000 * 3 * 4;
        privcar = 1000000;
        switch (penginapan)
        {
            case 1:
            cout << "Jenis Penginapan (perhari) \n1. Tradisional = Rp 800.000 \n2. Bintang 5 = Rp 2.000.000 \n3. Bintang 4 = Rp 1.500.000 \n4. Bintang 3 = Rp 1.000.000 \nPilih jenis penginapan: ";
            cin >> penginapan;
            switch(penginapan)
            {
                case 1:
                biayapenginapan = 800000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;


                    }

                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    
                    }
                }
                case 2:
                biayapenginapan = 2000000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                }
                case 3:
                biayapenginapan = 1500000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;


                    }

                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                }
                case 4:
                biayapenginapan = 1000000 * 2;
                cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
                cin >> penerbangan;
                switch(penerbangan)
                {
                    case 1:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 2300000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 1700000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 900000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }

                    case 2:
                    cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
                    cin >> pesawat;
                    switch(pesawat)
                    {
                        case 1:
                        biayapesawat = 4600000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 2:
                        biayapesawat = 3400000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        case 3:
                        biayapesawat = 1800000;
                        total = makan + privcar + biayapenginapan + biayapesawat;
                        cout << "Total biaya: " << total;
                        break;

                        default:
                        cout << "ERROR";
                        break;
                    }
                }
            }
        }
    }
    //cout << "Jenis Penginapan (perhari) \n1. Tradisional = Rp 800.000 \n2. Bintang 5 = Rp 2.000.000 \n3. Bintang 4 = Rp 1.500.000 \n4. Bintang 3 = Rp 1.000.000 \nPilih jenis penginapan: ";
    //cin >> penginapan;
    //cout << "1. Hanya keberangkatan \n2. Pulang dan Pergi \nPilih tipe penerbangan: ";
    //cin >> penerbangan;
    //cout << "1. Utama = Rp 2.300.000 \n2. Bisnis = Rp 1.700.000 \n3. Ekonomi = Rp 900.000 \nPilih tiket pesawat: ";
    //cin >> pesawat;

    return 0;
}