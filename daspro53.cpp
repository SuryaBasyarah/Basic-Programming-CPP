#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string artist[7] = {"Muse", "Muse", "Mr. Scruff", "Deadmau5", "Mark Ronson", "Mark Ronsom", "Animal Collective"};
    string title[7] = {"Black Holes and Revelation", "The Resistance", "Ninja Tuna", "For Lack of a Better Name", "Record Collection", "Version", "Merriweather Post Pavilion"};
    string price[7] = {"9.99", "11.99", "9.99", "9.99", "11.99", "12.99", "12.99"};
    string genre[7] = {"Rock", "Rock", "Electronica", "Eletro House", "Alternative Rock", "Pop","Electronica"};
    ofstream info;
    info.open("info.txt");
    info << "Artist" << "\t\t" << "Title" << "\t\t" << "Price" << "\t\t" << "Genre" << endl;
    for (int i = 0; i < 7; i++)
    {
        info << artist[i] << "\t\t" << title[i] << "\t\t" << price[i] << "\t\t" << genre[i] << endl;
    }
    info.close();
    return 0;
}