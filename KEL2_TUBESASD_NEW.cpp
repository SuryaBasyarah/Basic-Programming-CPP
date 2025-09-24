#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    string label;
    int price;
    int stock;
    Node *left_child, *right_sibling;
};

struct event
{
    string waktu;
    Node label;
};

typedef struct
{
    vector<string> tanggal;
    vector<string> syarat;
    vector<string> benefit;
}Promo;

struct EventNode
{
    string waktu;
    Node* menuNode;
    EventNode* next;
};

struct EventList
{
    EventNode* head;
    EventNode* tail;
};

//variasi global
string pilihan;
Node *root = nullptr;

//deklarasi fungi
Node *createNewTree(string label);
Node *addChild(Node *parent, string childLabel, int price, int stock);
void displayMenu();
void showMenuWithPrice(Node *root, int depth = 0, bool showPrice = true);
bool found = false;
Node *findItem(Node *start, const string &choice, bool &found);
Node *findItemAdmin(Node *start, string &menuadmin, bool &found);
Node *findCategory(Node *start, const string &categoryLabel, bool &found);
Node *findSubCategory(Node *start, const string &subCategoryLabel, bool &found);
Node *findItemcat(Node *start, const string &menuadmin, bool &found, bool searchCategory);
Node *addCategory(Node *parent, string categoryLabel);
void removeCategory(Node *parent, string categoryLabel);
void renameCategory(Node *category, string newLabel);
Node *addSubCategory(Node *parentCategory, string subCategoryLabel);
void removeSubCategory(Node *parentCategory, string subCategoryLabel);
void renameSubCategory(Node *subCategory, string newLabel);
Node *addItem(Node *category, string itemName, int price, int stock);
void removeItem(Node *category, string itemName);
void renameItem(Node *item, string newLabel);
void updatePrice(Node *item);
// void addPromo(Promo &promosi, const string &tanggal, const string &syarat, const string &benefit);
// void tambahPromo(Promo &promosi);
void addEvent(EventList& events, const string& waktu, Node* menuNode);
void removeEvent(EventList& events, const string& waktu);
void showEvents(const EventList& events);
void addPromoToMenu(Node* menu, EventList& events, const string& waktu, const string& choice);
void removePromoFromMenu(EventList& events, const string& waktu);
void showPromoMenu(Node* menu, const EventList& events);
void showPromo(const Promo &promosi);
void showItemsWithStock(Node *root);
void addStock(Node *menu, string &itemName, int additionalStock);
void showAdminMenu(Node *menu, Promo &promosi);

int main()
{
    system("cls");

    displayMenu();

    return 0;
}

//membuat tree baru
Node* createNewTree(string label)
{
    if (root != nullptr)
    {
        cout << "\nTree sudah dibuat" << endl;
        return nullptr;
    }
    else
    {
        Node* node = new Node();
        root = node;
        node->label = label;
        node->price = 0;
        node->stock = 0;
        node->left_child = nullptr;
        node->right_sibling = nullptr;
        return node;
    }
}

//menambah child dengan melihat parent
Node* addChild(Node* parent, string childLabel, int price, int stock)
{
    Node* child = new Node();
    child->label = childLabel;
    child->price = price;
    child->stock = stock;
    child->left_child = nullptr;
    child->right_sibling = nullptr;

    if (parent->left_child == nullptr)
    {
        parent->left_child = child;
    }
    else
    {
        Node* sibling = parent->left_child;
        while (sibling->right_sibling != nullptr)
        {
            sibling = sibling->right_sibling;
        }
        sibling->right_sibling = child;
    }
    return child;
}

//menampilkan semua menu
void displayMenu()
{
    Node *menu;
    Promo promosi;
    menu = createNewTree("Menu : ");

    //kategori
    Node* rotidankue = addItem(root, "Roti dan Kue", 0, 0);
    Node* minuman = addItem(root, "Minuman", 0, 0);
    Node* makananUtama = addItem(root, "Makanan Utama", 0, 0);

    //subkategori
    Node* viennoiseries = addItem(rotidankue, "Viennoiseries", 0, 0);
    Node* pastry = addChild(rotidankue, "Pastry", 0, 0);
    Node* bread = addChild(rotidankue, "Bread", 0, 0);
    Node* bun = addChild(rotidankue, "Bun", 0, 0);

    Node* juice = addItem(minuman, "Juice", 0, 0);
    Node* teh = addItem(minuman, "Teh", 0, 0);
    Node* kopi = addChild(minuman, "Kopi", 0, 0);

    Node* salad = addChild(makananUtama, "Salad", 0, 0);
    Node* sup = addChild(makananUtama, "Sup", 0, 0);
    Node* sandwich = addChild(makananUtama, "Sandwich", 0, 0);
    Node* pasta = addChild(makananUtama, "Pasta", 0, 0);

    //item menu
    //kategori Roti dan Kue
    //item dari subkategori Viennoiseries
    addChild(viennoiseries, "Croissant", 4, 0);
    addChild(viennoiseries, "Pain au Chocolate", 4, 0);
    addChild(viennoiseries, "Brioche", 4, 0);

    //item dari subkategori Pastry
    addChild(pastry, "Eclair", 4, 0);
    addChild(pastry, "Mille-feuille", 4, 0);
    addChild(pastry, "TarteTatin", 4, 0);
    addChild(pastry, "Tarlet", 4, 0);

    //item dari subkategori Bread
    addChild(bread, "Baguette", 4, 0);
    addChild(bread, "Sourdough", 4, 0);
    addChild(bread, "Brioche Long", 4, 0);

    //item dari subkategori Bun
    addChild(bun, "Bagel", 4, 0);
    addChild(bun, "Burger", 4, 0);
    addChild(bun, "Hotdog", 4, 0);
    
    //kategori Minuman
    //item dari subkategori Juice
    addChild(juice, "Apple Juice", 4, 0);
    addChild(juice, "Orange Juice", 4, 0);
    addChild(juice, "Strawberry Juice", 4, 0);
    
    //item dari subkategori Teh
    addChild(teh, "Earl Grey", 4, 0);
    addChild(teh, "Chamomile", 4, 0);
    addChild(teh, "English Breakfast", 4, 0);
    addChild(teh, "Darjeeling", 4, 0);
    addChild(teh, "Oolong", 4, 0);
    addChild(teh, "Matcha", 4, 0);
    addChild(teh, "Jasmine", 4, 0);

    //item dari subkategori Kopi
    addChild(kopi, "Long Black", 4, 0);
    addChild(kopi, "Cappucino", 4, 0);
    addChild(kopi, "Latte", 4, 0);
    addChild(kopi, "Espresso", 4, 0);
    addChild(kopi, "Machiato", 4, 0);
    addChild(kopi, "Piccolo", 4, 0);

    //kategori Makanan Utama
    //item dari subkategori Salad
    addChild(salad, "Caesar Salad", 4, 0);
    addChild(salad, "Caprese Salad", 4, 0);
    addChild(salad, "Waldorf Salad", 4, 0);
    addChild(salad, "Nicoise Salad", 4, 0);

    //item dari subkategori Sup
    addChild(sup, "Pumpkin Soup", 4, 0);
    addChild(sup, "Mushroom Soup", 4, 0);
    addChild(sup, "Corn Sup", 4, 0);
    
    //item dari subkategori sandwich
    addChild(sandwich, "Club Sandwich", 4, 0);
    addChild(sandwich, "Tuna Sandwich", 4, 0);
    
    //item dari subkategori Pasta
    addChild(pasta, "Gnocchi", 4, 0);
    addChild(pasta, "Aglio Olio", 4, 0);
    addChild(pasta, "Lasagna", 4, 0);
    addChild(pasta, "Fettucine", 4, 0);
    addChild(pasta, "Carbonara", 4, 0);

    //awal login
    int user;
    awal:
    cout << "======================\n   UperEast   \n======================\n";
    cout << "1. Admin\n2. Customer\n";
    cout << "Masuk Sebagai : ";
    cin >> user;

    if(user==1)
    {
        showAdminMenu(menu, promosi);
        goto awal;
    }
}

//menampilkan menu dengan harga
void showMenuWithPrice(Node* root, int depth , bool showPrice )
{
    if (root == nullptr)
    {
        return;
    }

    if (showPrice && root->price > 0)
    {
        for (int i = 0; i < depth; ++i)
        {
            cout << " ";
        }
        cout << root->label << " (Rp " << root->price << ")" << endl;
    }
    else
    {
        if (depth > 0)
        {
            for (int i = 0; i < depth; ++i)
            {
                cout << "|-- ";
            }
            cout << root->label << endl;
        }
    }

    if (root->left_child != nullptr)
    {
        showMenuWithPrice(root->left_child, depth + 1, showPrice);
    }

    if (root->right_sibling != nullptr)
    {
        showMenuWithPrice(root->right_sibling, depth, showPrice);
    }
}

//mencari item di menu
Node* findItem(Node* start, const string& choice, bool& found)
{

    if (start == nullptr)
    {
        found = false;
        return nullptr;
    }

    if (start->label == choice)
    {
        found = true;
        return start;
    }

    Node* foundItem = findItem(start->left_child, choice, found);
    if (foundItem != nullptr)
    {
        return foundItem;
    }

    return findItem(start->right_sibling, choice, found);
}

//mencari item di menu(admin)
Node* findItemAdmin(Node* start, string& menuadmin, bool& found)
{
    if (start == nullptr)
    {
        found = false;
        return nullptr;
    }

    if (start->label == menuadmin)
    {
        found = true;
        return start;
    }

    Node* foundItem = findItem(start->left_child, menuadmin, found);
    if (foundItem != nullptr)
    {
        return foundItem;
    }

    return findItem(start->right_sibling, menuadmin, found);
}

//mencari tegori di menu
Node* findCategory(Node* start,  string& categoryLabel, bool& found)
{
    if (start == nullptr)
    {
        found = false;
        return nullptr;
    }

    if (start->label == categoryLabel)
    {
        found = true;
        return start;
    }

    return findCategory(start->left_child, categoryLabel, found);
}

//mencari sub-kategori di menu
Node* findSubCategory(Node* start, const string& subCategoryLabel, bool& found)
{
    if (start == nullptr)
    {
        found = false;
        return nullptr;
    }

    if (start->label == subCategoryLabel)
    {
        found = true;
        return start;
    }

    Node* foundItem = findSubCategory(start->left_child, subCategoryLabel, found);
    if (foundItem != nullptr)
    {
        return foundItem;
    }

    return findSubCategory(start->right_sibling, subCategoryLabel, found);
}

//mencari kategori dan item
Node* findItemcat(Node* start,  string& menuadmin, bool& found, bool searchCategory)
{
    if (searchCategory)
    {
        return findCategory(start, menuadmin, found);
    }
    else
    {
        return findSubCategory(start, menuadmin, found);
    }
}

//menambah kategori
Node* addCategory(Node* parent, string categoryLabel)
{
    return addChild(parent, categoryLabel, 0, 0);
}

//menghapus kategori
void removeCategory(Node* parent, string categoryLabel)
{
    Node* categoryToRemove = findItem(parent, categoryLabel, found);

    if (found)
    {
        delete categoryToRemove;
    }
    else
    {
        cout << "Kategori tidak ditemukan." << endl;
    }
}

//edit kategori
void renameCategory(Node* category, string newLabel)
{
    category->label = newLabel;
}

//menambah kategori
Node* addSubCategory(Node* parentCategory, string subCategoryLabel)
{
    return addChild(parentCategory, subCategoryLabel, 0, 0);
}

//menghapus sub-kategori
void removeSubCategory(Node* parentCategory, string subCategoryLabel)
{
    Node* subCategoryToRemove = findItem(parentCategory, subCategoryLabel, found);

    if (found)
    {
        delete subCategoryToRemove;
    }
    else
    {
        cout << "Subkategori tidak ditemukan." << endl;
    }
}

//edit sub-kategori
void renameSubCategory(Node* subCategory, string newLabel)
{
    subCategory->label = newLabel;
}

//menambah item
Node* addItem(Node* category, string itemName, int price, int stock)
{
    return addChild(category, itemName, price, stock);
}

//menghapus item
void removeItem(Node* category, string itemName)
{
    Node* itemToRemove = findItem(category, itemName, found);

    if (found)
    {
        delete itemToRemove;
    }
    else
    {
        cout << "Item tidak ditemukan." << endl;
    }
}

//edit item
void renameItem(Node* item, string newLabel)
{
    item->label = newLabel;
}

//edit harga promosi
void updatePrice(Node* item)
{
    double newPrice;
    cout << "Masukkan harga baru untuk " << item->label << ": Rp";
    //masukkan menggunakan angka
    cin >> newPrice;
    item->price = newPrice;
}

//menghitung promosi
// void addPromo(Promo& promosi, const string& tanggal, const string& syarat, const string& benefit)
// {
//     promosi.tanggal.push_back(tanggal);
//     promosi.syarat.push_back(syarat);
//     promosi.benefit.push_back(benefit);
// };

//menambahkan promosi
// void tambahPromo(Promo& promosi)
// {
//     string tanggal, syarat, benefit;

//     cout << "Masukkan tanggal promo : ";
//     cin >> tanggal;
//     cin.ignore();

//     cout << "Masukkan syarat promo : ";
//     getline(cin, syarat);
    
//     cout << "Masukan benefit promo : ";
//     getline(cin, benefit);

//     addPromo(promosi, tanggal, syarat, benefit);
// }

// Menambahkan promo ke dalam list promo
void addEvent(EventList& events, const string& waktu, Node* menuNode)
{
    EventNode* newNode = new EventNode{waktu, menuNode, nullptr};
    if (events.head == nullptr)
    {
        events.head = newNode;
        events.tail = newNode;
    }
    else
    {
        events.tail->next = newNode;
        events.tail = newNode;
    }
}

// Menghapus promo dari list promo berdasarkan waktu
void removeEvent(EventList& events, const string& waktu)
{
    EventNode* current = events.head;
    EventNode* prev = nullptr;

    while (current != nullptr)
    {
        if (current->waktu == waktu)
        {
            if (prev == nullptr)
            {
                // Node yang akan dihapus adalah node pertama
                events.head = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }
}

// Menampilkan semua promo
void showEvents(const EventList& events)
{
    EventNode* current = events.head;
    while (current != nullptr)
    {
        cout << "Waktu: " << current->waktu << " | Menu: " << current->menuNode->label << endl;
        current = current->next;
    }
}

// Fungsi untuk menambah promo pada menu
void addPromoToMenu(Node* menu, EventList& events, const string& waktu, const string& choice)
{
    bool found = false;
    Node* menuItem = findItem(menu, choice, found);
    
    if (found && menuItem != nullptr)
    {
        addEvent(events, waktu, menuItem);
        cout << "Promo berhasil ditambahkan pada item " << menuItem->label << " pada waktu " << waktu << "." << endl;
    }
    else
    {
        cout << "Item tidak ditemukan." << endl;
    }
}

// Fungsi untuk menghapus promo pada menu berdasarkan waktu
void removePromoFromMenu(EventList& events, const string& waktu)
{
    if (events.head == nullptr)
    {
        cout << "Tidak ada promo yang aktif." << endl;
    }
    else
    {
        removeEvent(events, waktu);
        cout << "Promo pada waktu " << waktu << " berhasil dihapus." << endl;
    }
}

// Menampilkan semua promo pada menu
void showPromoMenu(Node* menu, const EventList& events)
{
    showMenuWithPrice(menu);
    showEvents(events);
}

//menampilkan promosi
void showPromo(const Promo& promosi)
{
    for (size_t i = 0; i < promosi.tanggal.size(); ++i)
    {
        cout << "Informasi Promo " << i + 1 << ":" << endl;
        cout << "Tanggal: " << promosi.tanggal[i] << " | "<<"Syarat Promo: " << promosi.syarat[i] << " | " << "Benefit Promo: " << promosi.benefit[i] << endl;
    }
}

void showItemsWithStock(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->stock > 0)
    {
        cout << root->label << " - Stock: " << root->stock << endl;
    }

    showItemsWithStock(root->left_child);
    showItemsWithStock(root->right_sibling);
}

void addStock(Node* menu, string& itemName, int additionalStock)
{
    bool found = false;
    Node* item = findItemAdmin(menu, itemName, found);

    if (found && item != nullptr)
    {
        item->stock += additionalStock;
        cout << "Stok untuk item " << itemName << " telah ditambahkan sebanyak " << additionalStock << ". Stok total sekarang: " << item->stock << endl;
    }
    else
    {
        cout << "Item tidak ditemukan dalam menu atau ada masalah dengan struktur data. Tidak dapat menambah stok." << endl;
    }
}

//menampilkan menu admin untuk kelola promosi
void showAdminMenu(Node* menu, Promo& promosi)
{
    int admin;
    backadmin:
    system("cls");
    cout << "=====================\n   UperEat\n=====================\n";
    cout << "1. Kelola Menu\n2. Kelola Stok\n3. Kelola Harga\n4. Kelola Promosi\n5. Kembali\n";
    cout << "Apa yg anda ingin kelola : ";
    //pilihan menggunakan integer atau angka
    cin >> admin;
    if(admin==1)
    {
        int kelolamenu;
        backkelolamenu:
        system("cls");
        cout << "========== Kelola Menu ============\n";
        cout << "1. Tambah Menu\n2. Hapus Menu\n3. Ubah Nama Menu\n4. Lihat Menu\n5. Kembali\n";
        cout << "Pilih kelola Menu : ";
        //pilihan menggunakan integer atau angka
        cin >> kelolamenu;
        if(kelolamenu == 1)
        {
            int tambahmenu;
            string pilihan;
            backtambahmenu:
            system("cls");
            cout << "########### Tambah Menu ############\n";
            cout << "1. Tambah Kategori\n2. Tambah Sub-Kategori\n3. Tambah Item\n4. Kembali\n";
            cout << "Tambah Menu : ";
            //pilih menggunakan integer atau angka
            cin >> tambahmenu;
            if(tambahmenu == 1)
            {
                tambahkategori:
                system("cls");
                cout << "----------- Tambah Kategori ------------\n";
                string kategoribaru;
                cout << "Masukkan nama kategori baru: ";
                //masukkan kategori dengan huruf kecil semua
                cin >> kategoribaru;
                Node* newCategory = addCategory(root, kategoribaru);
                loopkonfirmasi:
                cout << "Tambah kategori? (yes/no) : ";
                //ketik pilhan dengan menggunakan huruf kecil semua
                cin >> pilihan;
                if(pilihan=="yes")
                {
                    goto tambahkategori;
                }
                else if(pilihan=="no")
                {

                }
                else
                {goto loopkonfirmasi;}

            }
            else if (tambahmenu == 2 || tambahmenu == 3)
            {
                string kategoribaru, subkategoribaru, itembaru;
                system("cls");
                cout << "----------- Kategori -------------\n";
                cout << "Masukkan nama kategori: ";
                cin >> kategoribaru;


                Node* category = findItemAdmin(menu, kategoribaru, found);
                if (found)
                {
                    if (tambahmenu == 2)
                    {
                        tambahsubkategori:
                        cout << "Masukkan sub-kategori: ";
                        cin >> subkategoribaru;
                        Node* subcategory = addSubCategory(category, subkategoribaru);
                        loopkonfirmasi2:
                        cout << "apakah anda ingin menambah lagi(yes/no) : ";
                        cin >> pilihan;
                        if(pilihan=="yes")
                        {
                            goto tambahsubkategori;
                        }
                        else if(pilihan=="no")
                        {

                        }
                        else
                        {goto loopkonfirmasi2;}
                    }
                    else if (tambahmenu == 3)
                    {
                        tambahitem:
                        system("cls");
                        cout << "Masukkan sub-kategori: ";
                        cin >> subkategoribaru;

                        Node* subcategory = findItemAdmin(category, subkategoribaru, found);
                        if (found)
                        {
                            cout << "Masukan Item : ";
                            cin >> itembaru;
                            int price, stock;
                            cout << "Masukkan harga item : ";
                            cin >> price;
                            cout << "Masukkan stok item : ";
                            cin >> stock;
                            Node* newItem = addItem(subcategory, itembaru, price, stock);
                            loopkonfirmasi3:
                            cout << "Apakah anda ingin menambah lagi? (yes/no) : ";
                            cin >> pilihan;
                            if(pilihan=="yes")
                            {
                                goto tambahitem;
                            }
                            else if(pilihan=="no")
                            {

                            }
                            else
                            {goto loopkonfirmasi3;}
                        }
                        else
                        {
                            cout << "Sub-kategori tidak ditemukan" << endl;
                        }
                    }
                }
                else
                {
                    cout << "Kategori tidak ditemukan." << endl;
                }
            }
            else if (tambahmenu == 4)
            {
                goto backkelolamenu;
            }
            else
            {
                cout << "Pilihan tidak dalam daftar!";
                goto backtambahmenu;
            }

        }
        else if (kelolamenu == 2)
        {
            int hapusmenu;
            backhapusmenu:
            system("cls");
            cout << "########## Hapus Menu ###########\n";
            cout << "1. Hapus Kategori\n2. Hapus Sub-Kategori\n3. Hapus Item\n4. Kembali\n" << endl;
            cout << "Apa yg ingin anda Hapus : ";
            cin >> hapusmenu;
            if (hapusmenu == 1)
            {
                string kategorihapus;
                hapuskategori:
                system("cls");
                cout << "Masukkan nama kategori yang ingin dihapus : ";
                cin >> kategorihapus;
                loopkonfirmasi5:
                    cout << "Apakah anda ingin menghapus lagi? (yes/no) : ";
                    cin >> pilihan;
                    if(pilihan=="yes")
                    {
                        goto hapuskategori;
                    }
                    else if(pilihan=="no")
                    {

                    }
                    else
                    {goto loopkonfirmasi5;}

                removeCategory(menu, kategorihapus);
            } 
            else if (hapusmenu == 2)
            {
                hapussubkategori:
                system("cls");
                string kategorihapus, subkategorihapus;
                cout << "Masukkan nama kategori: ";
                cin >> kategorihapus;

                Node* categoryToRemove = findItemAdmin(menu, kategorihapus, found);
                if (found)
                {
                    cout << "Masukkan nama sub-kategori yang ingin dihapus: ";
                    cin >> subkategorihapus;

                    removeSubCategory(categoryToRemove, subkategorihapus);
                    loopkonfirmasi4:
                    cout << "apakah anda ingin menambah lagi(yes/no) : ";cin >> pilihan;
                    if(pilihan=="yes"){
                        goto hapussubkategori;
                    } else if(pilihan=="no"){

                    } else {goto loopkonfirmasi4;}
                } else {
                    cout << "Kategori tidak ditemukan." << endl;
                }
            } else if (hapusmenu == 3) {
                hapusitemm:
                system("cls");
                string kategorihapus, subkategorihapus, itemhapus;
                cout << "Masukkan nama kategori: ";
                cin >> kategorihapus;

                Node* categoryToRemove = findItemAdmin(menu, kategorihapus, found);
                if (found) {
                    cout << "Masukkan nama sub-kategori: ";
                    cin >> subkategorihapus;

                    Node* subcategoryToRemove = findItemAdmin(categoryToRemove, subkategorihapus, found);
                    if (found) {
                        cout << "Masukkan nama item yang ingin dihapus: ";
                        cin >> itemhapus;
                        loopkonfirmasi6:
                        cout << "apakah anda ingin menambah lagi(yes/no) : ";cin >> pilihan;
                        if(pilihan=="yes"){
                            goto hapusitemm;
                        } else if(pilihan=="no"){

                        } else {goto loopkonfirmasi6;}
                        removeItem(subcategoryToRemove, itemhapus);
                    } else {
                        cout << "Sub-kategori tidak ditemukan." << endl;
                    }
                } else {
                    cout << "Kategori tidak ditemukan." << endl;
                }
            } else if (hapusmenu == 4) {
                goto backkelolamenu;
            } else {
                goto backhapusmenu;
            }
        }
        else if (kelolamenu == 3) {
            int ubahmenu;
            backubahmenu:
            system("cls");
            cout << "1.Ubah Nama Kategori\n2.Ubah Nama-Subkategori\n3.Ubah Nama Item\n4.Kembali" << endl;
            cout << "Apa yg ingin anda ubah : "; cin >> ubahmenu;
            if(ubahmenu == 1) {
                ubahnamakategori:
                system("cls");
                string kategorilama, kategoribaru;
                cout << "Masukkan nama kategori yang ingin diubah: ";
                cin >> kategorilama;

                Node* categoryToRename = findItemcat(menu, kategoribaru, found, true);
                if (found) {
                    cout << "Masukkan nama kategori baru: ";
                    cin >> kategoribaru;
                    renameCategory(categoryToRename, kategoribaru);
                } else {
                    cout << "Kategori tidak ditemukan." << endl;
                }
            } else if(ubahmenu == 2) {
                ubahnamasubkategori:
                    system("cls");
                string kategorilama, kategoribaru, subkategorilama, subkategoribaru;
                cout << "Masukkan nama kategori: ";
                cin >> kategorilama;

                Node* categoryToRename = findItemcat(menu, kategoribaru, found, true);
                if (found) {
                    cout << "Masukkan nama sub-kategori yang ingin diubah: ";
                    cin >> subkategorilama;

                    Node* subcategoryToRename = findItemcat(categoryToRename, subkategoribaru, found, false);
                    if (found) {
                        cout << "Masukkan nama sub-kategori baru: ";
                        cin >> subkategoribaru;
                        loopkonfirmasi8:
                        cout << "apakah anda ingin menambah lagi(yes/no) : ";cin >> pilihan;
                        if(pilihan=="yes"){
                            goto ubahnamasubkategori;
                        } else if(pilihan=="no"){

                        } else {goto loopkonfirmasi8;}
                        renameSubCategory(subcategoryToRename, subkategoribaru);
                    } else {
                        cout << "Sub-kategori tidak ditemukan." << endl;
                    }
                } else {
                    cout << "Kategori tidak ditemukan." << endl;
                }
            } else if (ubahmenu == 3) {
                ubahnamaitem:
                system("cls");
                string kategorilama, subkategorilama, itemlama, itembaru;
                cout << "Masukkan nama kategori: ";
                cin >> kategorilama;

                Node* category = findItemAdmin(menu, kategorilama, found);
                if (found) {
                    cout << "Masukkan nama sub-kategori: ";
                    cin >> subkategorilama;

                    Node* subcategory = findItemAdmin(category, subkategorilama, found);
                    if (found) {
                        cout << "Masukkan nama item yang ingin diubah: ";
                        cin >> itemlama;

                        Node* itemToRename = findItemAdmin(subcategory, itemlama, found);
                        if (found) {
                            cout << "Masukkan nama item baru: "; cin >> itembaru;
                            loopkonfirmasi9:
                            cout << "apakah anda ingin menambah lagi(yes/no) : ";cin >> pilihan;
                            if(pilihan=="yes"){
                                goto ubahnamaitem;
                            } else if(pilihan=="no"){

                            } else {goto loopkonfirmasi9;}
                            renameItem(itemToRename, itembaru);
                        } else {
                            cout << "Item tidak ditemukan." << endl;
                        }
                    } else {
                        cout << "Sub-kategori tidak ditemukan." << endl;
                    }
                } else {
                    cout << "Kategori tidak ditemukan." << endl;
                }
            } else if (ubahmenu == 4){
                goto backubahmenu;
            } else goto backkelolamenu;

        }else if (kelolamenu == 4) {
            string konfirmasi;
            system("cls");
            kelolamenu4:
            showMenuWithPrice(menu);
            cout << "apakah anda ingin kembali (yes/no) : "; cin >> konfirmasi;
            if (konfirmasi == "yes"){
                goto backadmin;
            } else if (konfirmasi == "no"){

            } else {
                cout << "pilihan tidak valid!!" << endl;
                goto kelolamenu4;
            }
        }else if (kelolamenu == 5){
            goto backadmin;
        } else {
            cout << "pilihan tidak valid!!" << endl;
            goto backkelolamenu;
        }
    }
    else if (admin == 2) {
        int kelolastok;
        backkelolastok:
        system("cls");
        cout << "1.Cek Stok\n2.Tambah Stok\n3.Kembali\n";
        cout << "pilih kelola : "; cin >> kelolastok;
        if (kelolastok == 1){
            string pilihan;
            showItemsWithStock(menu);
            cout << "apakah anda ingin kembali(yes/no) : "; cin >> pilihan;
            if(pilihan=="yes"){
                goto backkelolastok;
            }
            else {
                goto backadmin;
            }
        } else if (kelolastok == 2){
            string pilihitem;
            int tambahstok;

            cout << "Masukkan nama item untuk menambah stok: ";
            cin >> pilihitem;

            cout << "Masukkan jumlah stok yang ingin ditambahkan: ";
            cin >> tambahstok;

            addStock(menu, pilihitem, tambahstok);
            goto backkelolastok;
        } else if (kelolastok == 3) {
            goto backadmin;
        } else {
            cout << "pilihan tidak valid!!"; goto backkelolastok;
        }
    }
    else if (admin == 3){
        int kelolaharga;
        backkelolaharga:
        system("cls");
        cout << "1.Cek Harga\n2.Ubah Harga\n3.Kembali\n";
        cout << "pilih kelola : "; cin >> kelolaharga;
        if (kelolaharga == 1){
            string pilihan;
            showMenuWithPrice(menu);
            konfirmasinj:
            cout << "apakah anda ingin kembali(yes/no) : "; cin >> pilihan;
            if (pilihan == "yes"){
                goto backkelolaharga;
            } else if(pilihan=="no"){
            } else{goto konfirmasinj;}
        } else if (kelolaharga == 2){
            bool found = false;
            string pilihitem;
            cout << "Masukkan nama item untuk diubah harga: ";cin >> pilihitem;
            Node* itemToUpdate = findItemAdmin(menu, pilihitem, found);

            if (found && itemToUpdate != nullptr) {
                updatePrice(itemToUpdate);
            } else {
                cout << "Item tidak ditemukan." << endl;
            }
        } else if (kelolaharga == 3){
            goto backadmin;
        } else {
            cout << "pilihan tidak valid!!"; goto backkelolaharga;
        }
    }
    else if (admin == 4){
        int kelolapromo;
        backkelolapromo:
        system("cls");
        cout << "1.Cek Promo\n2.Tambah Promo\n3.Kembali\n";
        cout << "pilih kelola : "; cin >> kelolapromo;
        if(kelolapromo == 1){
            showPromo(promosi);
            loopkonfirmasipromo:
                cout << "apakah anda ingin kembali(yes/no) : ";cin >> pilihan;
                if(pilihan=="yes"){
                    goto backkelolapromo;
                } else if(pilihan=="no")
                {

                }
                else
                {
                    goto loopkonfirmasipromo;
                }
        }
        else if (kelolapromo == 2)
        {
            addPromoToMenu(menu, EventList& events, const string& waktu, const string& choice);
            loopkonfirmasipromo3:
                cout << "apakah anda ingin kembali(yes/no) : ";
                cin >> pilihan;
                if(pilihan=="yes")
                {
                    goto backkelolapromo;
                }
                else if(pilihan=="no")
                {

                }
                else
                {
                    goto loopkonfirmasipromo3;
                }
        }
    }
}
