#include <iostream>
using namespace std;

float phi = 3.14;

void luas_tabung(float tinggi, float jari_jari)
{
    float luas, selimut_tabung;
    selimut_tabung = jari_jari * tinggi;
    luas = 2 * phi + selimut_tabung;
    cout << "Luas tabung: " << luas << endl;
}

void luas_piramida(float panjang_alas, float tinggi_sisi)
{
    float luas_alas, luas_sisi, luas;
    luas_alas = panjang_alas * panjang_alas;
    luas_sisi = 0.5 * panjang_alas * tinggi_sisi;
    luas = luas_alas + 4 * luas_sisi;
    cout << "Luas piramida: " << luas << endl;
}

void luas_kerucut(float jari_jari, float tinggi_selimut)
{
    float luas_alas, luas_selimut, luas;
    luas_alas = phi * jari_jari * jari_jari;
    luas_selimut = 2 * phi * tinggi_selimut;
    luas = luas_alas + luas_selimut;
    cout << "Luas Kerucut: " << luas << endl;
}

int main()
{
    float jari_jari_tabung, tinggi_tabung, panjang_alas_piramida, tinggi_sisi_piramida, jari_jari_kerucut, tinggi_selimut_kerucut;
    cout << "Jari jari kerucut: ";
    cin >> jari_jari_tabung;
    cout << "Tinggi tabung: ";
    cin >> tinggi_tabung;
    luas_tabung(tinggi_tabung, jari_jari_tabung);

    cout << "Panjang alas piramida: ";
    cin >> panjang_alas_piramida;
    cout << "Tinggi sisi piramida: ";
    cin >> tinggi_sisi_piramida;
    luas_piramida(panjang_alas_piramida, tinggi_sisi_piramida);

    cout << "Jari jari kerucut: ";
    cin >> jari_jari_kerucut;
    cout << "Tinggi selimut kerucut: ";
    cin >> tinggi_selimut_kerucut;
    luas_kerucut(jari_jari_kerucut, tinggi_selimut_kerucut);
    return 0;
}
