#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

string categoryName, subCategoryName, ItemName;
float ItemPrice;
int ItemStock;



struct Node {
    string name;
    float price;
    int stock;
    Node* leftChild;
    Node* rightSibling;

    vector<Node*> children;

    explicit Node(const string& name) {
        this->name = name;
        this->price = 0;
        this->stock = 0;
        this->leftChild = nullptr;
        this->rightSibling = nullptr;
    }

    Node(const string& name, float price, int stock) {
        this->name = name;
        this->price = price;
        this->stock = stock;
        this->leftChild = nullptr;
        this->rightSibling = nullptr;
    }

    bool isItem() const {
        return this->price != 0 || this->stock != 0;
    }
};

Node* MenuRoot;

enum Type { Item, Event };

struct TreeNodeEvent {
    string eventName;
    Node* menuItem;
    vector<TreeNodeEvent*> Children;  // Dynamic array to store children
    Type type;
};


//Fungsi menambahkan node kategori dan subkategori pada tree
Node* addCategory_n_Sub(Node* parent, const string& name) {
    if (!parent) return nullptr;

    //Jika item sudah tersedia
    Node* current = parent->leftChild;
    while (current) {
        if (current->name == name) {
            cout << "gagal ditambahkan " << name << " sudah ada" << endl;
            return current;
        }
        current = current->rightSibling;
    }

    //Jika item belum tersedia
    if (parent->leftChild == nullptr) {
        parent->leftChild = new Node(name);
        return parent->leftChild;
    } else {
        Node* sibling = parent->leftChild;
        while (sibling->rightSibling) {
            sibling = sibling->rightSibling;
        }
        sibling->rightSibling = new Node(name);
        return sibling->rightSibling;
    }

}

//Fungsi menambahkan node item pada tree
Node* addItem(Node* parent, const string& name, float price, int stock) {
    if (!parent) return nullptr;

    // Check if the item already exists
    Node* current = parent->leftChild;
    while (current) {
        if (current->name == name) {
            cout << "gagal ditambahkan " << name << " sudah ada" << endl;
            return current;
        }
        current = current->rightSibling;
    }

    // If the item does not exist, add a new one
    if (parent->leftChild == nullptr) {
        parent->leftChild = new Node(name, price, stock);
        return parent->leftChild;
    } else {
        Node* sibling = parent->leftChild;
        while (sibling->rightSibling) {
            sibling = sibling->rightSibling;
        }
        sibling->rightSibling = new Node(name, price, stock);
        return sibling->rightSibling;
    }
}

// Fungsi untuk mencari kategori atau item dengan nama tertentu
Node* findNode(Node* root, const string& name) {
    // cout << "kontol";
    if (!root) return nullptr;

    // cout << "test0";
    if (root->name == name) return root;
    // cout << "test1";

    Node* foundNode = findNode(root->leftChild, name);
    // cout << "test2";
    if (foundNode) return foundNode;

    // Iterate through right siblings
    Node* sibling = root->rightSibling;
    while (sibling) {
        foundNode = findNode(sibling, name);
        if (foundNode) return foundNode;
        sibling = sibling->rightSibling;
    }

    return nullptr;
}

//Fungsi rekursif untuk delete node
void deleteSubTree(Node* node) {
    if (!node) return;

    deleteSubTree(node->leftChild);
    Node* rightSibling = node->rightSibling;
    delete node;

    if (rightSibling) {
        deleteSubTree(rightSibling);
    }
}

//Untuk menghapus node pada tree
Node* deleteNode(Node* root, const string& name) {
    if (!root) return nullptr;
    //jika node tersebut root
    if (root->name == name) {
        Node* newRoot = root->rightSibling;
        deleteSubTree(root);
        return newRoot;
    }

    //Jika node target tersebut di rightsibling
    Node* sibling = root->leftChild;
    Node* prevSibling = nullptr;
    while (sibling && sibling->rightSibling) {
        if (sibling->rightSibling->name == name) {
            deleteSubTree(sibling->rightSibling);//menghapus rightsibling tersebut
            sibling->rightSibling = sibling->rightSibling->rightSibling;
            return root;
        }
        prevSibling = sibling;
        sibling = sibling->rightSibling;
    }

    //pencarian rekursif
    root->leftChild = deleteNode(root->leftChild, name);
    root->rightSibling = deleteNode(root->rightSibling, name);

    return root;
}

// Fungsi untuk mengganti isi dari kategori atau item pada tree
void editNode(Node* root, const string& name, const string& newName, float newPrice = 0, int newStock = 0) {
    Node* node = findNode(root, name);
    if (!node) {
        cout << "Node tidak ditemukan" << endl;
        return;
    }

    //jika new name sudah ada di tree
    while (node) {
        if (node->name == newName) {
            cout << "gagal ditambahkan " << newName << " sudah ada" << endl;
            return;
        }
        node = node->rightSibling;
    }
    node = findNode(root, name);

    //Edit item jika node berupa item
    if (node->isItem()) {
        node->name = newName;
        node->price = newPrice;
        node->stock = newStock;
    //jika node bukan item
    } else {
        node->name = newName;
    }
}

// Fungsi untuk menampilkan tree
void displayTree(Node* root, int depth = 0) {
    if (!root) return;

    string indent(depth * 2, ' '); // Membuat indentasi
    cout << indent << root->name << " " << root->price << " " << root->stock << endl; // Menampilkan nama kategori atau item

    if (root->leftChild) {
        displayTree(root->leftChild, depth + 1);
    }

    if (root->rightSibling) {
        displayTree(root->rightSibling, depth);
    }
}

// Fungsi untuk mengisi tree dengan data
void fillMenu(Node* root, const vector<tuple<string, vector<pair<string, vector<tuple<string, float, int>>>>>>& menuData) {
    for (const auto& categoryData : menuData) {
        // Extracting values from categoryData tuple
        const string& categoryName = get<0>(categoryData);
        const vector<pair<string, vector<tuple<string, float, int>>>>& subCategories = get<1>(categoryData);

        // Creating a Node* for the category
        Node* categoryNode = addCategory_n_Sub(root, categoryName);

        for (const auto& subCategoryData : subCategories) {
            // Extracting values from subCategoryData tuple
            const string& subCategoryName = subCategoryData.first;
            const vector<tuple<string, float, int>>& items = subCategoryData.second;

            // Creating a Node* for the subcategory
            Node* subCategoryNode = addCategory_n_Sub(categoryNode, subCategoryName);

            for (const auto& itemData : items) {
                // Extracting values from itemData tuple
                const string& itemName = get<0>(itemData);
                float itemPrice = get<1>(itemData);
                int itemStock = get<2>(itemData);

                // Creating a Node* for the item
                addItem(subCategoryNode, itemName, itemPrice, itemStock);
            }
        }
    }
}

//Fungsi-fungsi implementasi untuk dijalankan pada terminal
Node* add_category_terminal(Node* root) {
    cout << "Masukkan Kategori: ";
    getline(cin, categoryName);

    return addCategory_n_Sub(root, categoryName);
}

Node* add_Sub_category_terminal(Node* root) {
    cout << "Kategori yang akan ditambahkan : ";
    getline(cin, categoryName);
    Node* categoryNode = findNode(root, categoryName);

    if (categoryNode) {
        cout << "Masukkan sub Kategori : ";
        getline(cin, subCategoryName);
        return addCategory_n_Sub(categoryNode, subCategoryName);
    } else {
        cout << "Kategori tidak ditemukan.\n";
        return nullptr;
    }
}

Node* add_Item_terminal(Node* root){
    cout << "Kategori yang akan ditambahkan : ";
    getline(cin, categoryName);
    Node* categoryNode = findNode(root, categoryName);

    if (categoryNode) {
        cout << "Sub Kategori yang akan ditambahkan : ";
        getline(cin, subCategoryName);
        Node* subCategoryNode = findNode(categoryNode, subCategoryName);
        
        if (subCategoryNode) {
        cout << "Masukkan Nama Item : ";
        getline(cin, ItemName);
        cout << "Masukkan Harga Item : ";
        cin >> ItemPrice;
        cout << "Masukkan Stok Item : ";
        cin >> ItemStock;
        return addItem(subCategoryNode, ItemName, ItemPrice, ItemStock);
        } else {
            cout << "Sub Kategori Tidak ditemukan.\n";
            return nullptr;
        }
    } else {
        cout << "Kategori tidak ditemukan.\n";
        return nullptr;
    }
}

void delete_category_terminal(Node* root){
    cout << "Masukkan Kategori: ";
    getline(cin, categoryName);
    deleteNode(root, categoryName);
}

void delete_Sub_category_terminal(Node* root){
    cout << "Kategori yang sub kategori nya akan dikurangi : ";
    getline(cin, categoryName);
    Node* categoryNode = findNode(root, categoryName);

    if (categoryNode) {
        cout << "Masukkan sub Kategori : ";
        getline(cin, subCategoryName);
        deleteNode(categoryNode, subCategoryName);
    } else {
        cout << "Kategori tidak ditemukan.\n";
    }
}

void delete_Item_terminal(Node* root){
    cout << "Kategori yang sub kategori nya akan dikurangi : ";
    getline(cin, categoryName);
    Node* categoryNode = findNode(root, categoryName);

    if (categoryNode) {
        cout << "Sub Kategori yang item nya akan dikurangi : ";
        getline(cin, subCategoryName);
        Node* subCategoryNode = findNode(categoryNode, subCategoryName);
        
        if (subCategoryNode) {
        cout << "Masukkan Nama Item : ";
        getline(cin, ItemName);
        deleteNode(subCategoryNode, ItemName);
        } else {
            cout << "Sub Kategori Tidak ditemukan.\n";
        }
    } else {
        cout << "Kategori tidak ditemukan.\n";
    }
}

void edit_category_terminal(Node* root){
    string newcategoryName;
    cout << "Masukkan Kategori: ";
    getline(cin, categoryName);
    cout << "Masukkan nama Kategori baru: ";
    getline(cin, newcategoryName);

    editNode(root, categoryName, newcategoryName);
}

void edit_Sub_category_terminal(Node* root){
    string newSubcategoryName;
    cout << "Kategori yang sub kategori nya akan diedit : ";
    getline(cin, categoryName);
    Node* categoryNode = findNode(root, categoryName);

    if (categoryNode) {
        cout << "Masukkan Sub Kategori: ";
        getline(cin, subCategoryName);
        cout << "Masukkan nama Sub Kategori baru: ";
        getline(cin, newSubcategoryName);
        editNode(root, subCategoryName, newSubcategoryName);
    } else {
        cout << "Kategori tidak ditemukan.\n";
    }
}

void edit_Item_terminal(Node* root){
    string newitemName;
   cout << "Kategori yang sub kategori nya akan diedit : ";
    getline(cin, categoryName);
    Node* categoryNode = findNode(root, categoryName);

    if (categoryNode) {
        cout << "Sub Kategori yang item nya akan diedit : ";
        getline(cin, subCategoryName);
        Node* subCategoryNode = findNode(categoryNode, subCategoryName);
        
        if (subCategoryNode) {
        cout << "Masukkan Item: ";
        getline(cin, ItemName);
        cout << "Masukkan nama Item baru: ";
        getline(cin, newitemName);
        editNode(root, ItemName, newitemName);
        } else {
            cout << "Sub Kategori Tidak ditemukan.\n";
        }
    } else {
        cout << "Kategori tidak ditemukan.\n";
    } 
}

void search_available(Node* root){
    string target;
    cout << "Masukkan Item yang ingin dicari : ";
    getline (cin, target);
    Node* node = findNode(root, target);
    if (node){
        cout << "Item tersedia \n";
    } else {
        cout << "Item tidak tersedia " << endl;
    }

}

//isi dari tree yang telah disediakan
void insertall(Node* root) {
    vector<tuple<string, vector<pair<string, vector<tuple<string, float, int>>>>>> menuData = {
        {"Roti dan kue", {
            {"Viennoiseries", {
                {"Croissant", 1.99f, 10},
                {"Pain au Chocolat", 2.49f, 5},
                {"Brioche", 2.99f, 7}
            }},
            {"Pastry", {
                {"Éclair", 3.49f, 10},
                {"Mille-feuille", 4.49f, 6},
                {"Tarte Tatin", 3.99f, 4}
            }},
            {"Bread", {
                {"Baguette", 1.99f, 15},
                {"Sourdough", 2.99f, 10}
            }},
            {"Bun", {
                {"Bagel", 1.49f, 8},
                {"Burger", 1.99f, 12},
                {"Hotdog", 1.99f, 14}
            }}
        }},
        {"Minuman", {
            {"Juice", {
                {"Apple Juice", 3.49f, 20},
                {"Orange Juice", 3.49f, 20},
                {"Strawberry Juice", 3.99f, 15}
            }},
            {"Teh", {
                {"Earl Grey", 2.99f, 30},
                {"Chamomile", 2.99f, 30}
            }},
            {"Kopi", {
                {"Long black", 2.49f, 25},
                {"Cappuccino", 2.99f, 25}
            }}
        }},
        {"Makanan Utama", {
            {"Salad", {
                {"Caesar Salad", 4.99f, 8},
                {"Caprese Salad", 5.49f, 6}
            }},
            {"Sup", {
                {"Pumpkin soup", 3.99f, 10},
                {"Mushroom soup", 3.99f, 10}
            }},
            {"Pasta", {
                {"Gnocchi", 6.99f, 5},
                {"Aglio Olio", 5.99f, 7}
            }}
        }}
    };
     // Fill the menu tree with the data
    fillMenu(root, menuData);
}

struct PromotionNode
{
    bool Status;
    struct StartDate
    {
        int day, month, year;
    } StartDate;

    struct EndDate
    {
        int day, month, year;
    } EndDate;

    int PromotionType;
    string PaymentMethod;
    int MinimumPayment;
    string Product;
    string Benefit;
    PromotionNode *next;
};

PromotionNode *head = nullptr;
int numberOfPromotions = 0;

void AddPromotion(bool status,
                  int startDate_day, int startDate_month, int startDate_year,
                  int endDate_day, int endDate_month, int endDate_year,
                  int promotiontype, string paymentmethod, int minimumpayment, string benefit, string product)
{
    if (endDate_year < startDate_year || (endDate_year == startDate_year && endDate_month < startDate_month) || (endDate_year == startDate_year && endDate_month == startDate_month && endDate_day < startDate_day))
    {
        cout << "Error: End date cannot be earlier than start date!" << endl;
        return;
    }

    if (startDate_day < 1 || startDate_day > 31 || startDate_month < 1 || startDate_month > 12 ||
        endDate_day < 1 || endDate_day > 31 || endDate_month < 1 || endDate_month > 12)
    {
        cout << "Error: Invalid date!" << endl;
        return;
    }

    if (promotiontype != 1 && promotiontype != 2)
    {
        cout << "Error: Invalid promotion type! Please enter either 1 for Discount or 2 for Free Item." << endl;
        return;
    }

    PromotionNode *newNode = new PromotionNode;
    newNode->Status = status;
    newNode->StartDate.day = startDate_day;
    newNode->StartDate.month = startDate_month;
    newNode->StartDate.year = startDate_year;
    newNode->EndDate.day = endDate_day;
    newNode->EndDate.month = endDate_month;
    newNode->EndDate.year = endDate_year;
    newNode->PromotionType = promotiontype;
    newNode->PaymentMethod = paymentmethod;
    newNode->MinimumPayment = minimumpayment;
    newNode->Product = product;
    newNode->Benefit = benefit;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        PromotionNode *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << endl
         << "Promotion added." << endl;
    numberOfPromotions++;
}
// Fungsi ini digunakan untuk menambahkan sebuah promosi baru ke dalam daftar promosi.
// Parameter:
// - status: status promosi (aktif atau tidak)
// - startDate_day, startDate_month, startDate_year: tanggal mulai promosi
// - endDate_day, endDate_month, endDate_year: tanggal berakhir promosi
// - promotiontype: jenis promosi (1 untuk Diskon, 2 untuk Barang Gratis)
// - paymentmethod: metode pembayaran yang berlaku untuk promosi
// - minimumpayment: jumlah pembayaran minimum yang diperlukan untuk memenuhi syarat promosi
// - benefit: manfaat yang diberikan oleh promosi
// - product: produk yang tercakup dalam promosi

void EditPromotion(int selectedpromotion, bool status,
                   int startDate_day, int startDate_month, int startDate_year,
                   int endDate_day, int endDate_month, int endDate_year,
                   int promotiontype, string paymentmethod, int minimumpayment, string benefit, string product)
{
    PromotionNode *current = head;
    int index = 1;

    while (current != nullptr && index < selectedpromotion)
    {
        current = current->next;
        index++;
    }

    if (current == nullptr)
    {
        cout << "Error: No promotions exist yet!" << endl;
        return;
    }

    if (endDate_year < startDate_year || (endDate_year == startDate_year && endDate_month < startDate_month) || (endDate_year == startDate_year && endDate_month == startDate_month && endDate_day < startDate_day))
    {
        cout << "Error: End date is earlier than start date!" << endl;
        return;
    }

    if (startDate_day < 1 || startDate_day > 31 || startDate_month < 1 || startDate_month > 12 ||
        endDate_day < 1 || endDate_day > 31 || endDate_month < 1 || endDate_month > 12)
    {
        cout << "Error: Invalid date!" << endl;
        return;
    }

    if (promotiontype != 1 && promotiontype != 2)
    {
        cout << "Error: Invalid promotion type! Please enter either 1 for Discount or 2 for Free Item." << endl;
        return;
    }

    current->Status = status;
    current->StartDate.day = startDate_day;
    current->StartDate.month = startDate_month;
    current->StartDate.year = startDate_year;
    current->EndDate.day = endDate_day;
    current->EndDate.month = endDate_month;
    current->EndDate.year = endDate_year;
    current->PromotionType = promotiontype;
    current->PaymentMethod = paymentmethod;
    current->MinimumPayment = minimumpayment;
    current->Product = product;
    current->Benefit = benefit;

    cout << "Promotion edited." << endl;
}
// Fungsi ini digunakan untuk mengedit promosi yang sudah ada dalam daftar promosi.
// Parameter:
// - selectedpromotion: nomor promosi yang akan diedit
// - status: status baru promosi (aktif atau tidak)
// - startDate_day, startDate_month, startDate_year: tanggal mulai baru promosi
// - endDate_day, endDate_month, endDate_year: tanggal berakhir baru promosi
// - promotiontype: jenis promosi baru (1 untuk Diskon, 2 untuk Barang Gratis)
// - paymentmethod: metode pembayaran baru yang berlaku untuk promosi
// - minimumpayment: jumlah pembayaran minimum baru yang diperlukan untuk memenuhi syarat promosi
// - benefit: manfaat baru yang diberikan oleh promosi
// - product: produk baru yang tercakup dalam promosi

void DeletePromotion(int selectedpromotion)
{
    if (selectedpromotion <= 0 || selectedpromotion > numberOfPromotions)
        return;

    PromotionNode *current = head;
    PromotionNode *previous = nullptr;
    int index = 1;

    while (current != nullptr && index < selectedpromotion)
    {
        previous = current;
        current = current->next;
        index++;
    }

    if (current == nullptr)
        return;

    if (previous == nullptr)
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    delete current;

    cout << "Promotion " << selectedpromotion << " deleted." << endl;
    numberOfPromotions--; // update jumlah promosi yang tersedia
}
// Fungsi ini digunakan untuk menghapus promosi dari daftar promosi berdasarkan nomor promosi.
// Parameter:
// - selectedpromotion: nomor promosi yang akan dihapus

void DisplayPromotions()
{
    PromotionNode *current = head;
    int index = 1;

    while (current != nullptr)
    {
        cout << "------------------------" << endl;
        cout << "Promotion " << index << ":" << endl;
        cout << "Promotion Type: ";
        switch (current->PromotionType)
        {
        case 1:
            cout << "Discount" << endl;
            break;

        case 2:
            cout << "Free Item" << endl;
            break;

        default:
            break;
        }
        cout << "Status: " << (current->Status ? "Active" : "Inactive") << endl;
        cout << "Start Date: " << current->StartDate.day << "/" << current->StartDate.month << "/" << current->StartDate.year << endl;
        cout << "End Date: " << current->EndDate.day << "/" << current->EndDate.month << "/" << current->EndDate.year << endl;
        cout << "Terms and Condition: " << endl;
        cout << "1. Payment method: " << current->PaymentMethod << endl;
        cout << "2. Minimum payment: " << current->MinimumPayment << endl;
        cout << "3. Product: " << current->Product << endl;
        cout << "Benefit: " << current->Benefit << endl;
        cout << "------------------------" << endl;
        cout << endl;

        current = current->next;
        index++;
    }
}
// Fungsi ini digunakan untuk menampilkan semua promosi yang tersedia beserta detailnya.

void ApplyPromotion(int CurrentDate, int CurrentMonth, int CurrentYear, int TotalPrice, string PaymentMethod, string product)
{
    PromotionNode *current = head;

    while (current != nullptr)
    {
        if (current->Status &&
            current->StartDate.year <= CurrentYear && current->StartDate.month <= CurrentMonth && current->StartDate.day <= CurrentDate &&
            current->EndDate.year >= CurrentYear && current->EndDate.month >= CurrentMonth && current->EndDate.day >= CurrentDate &&
            current->MinimumPayment < TotalPrice && current->PaymentMethod == PaymentMethod && current->Product == product)
        {
            cout << "You got a discount!" << endl;
            cout << "Your benefit: " << current->Benefit << endl;
            return;
        }
        current = current->next;
    }
    cout << "------------------------" << endl;
    cout << "No discount applied." << endl;
    cout << "------------------------" << endl;
}
// Fungsi ini digunakan untuk menerapkan promosi berdasarkan tanggal, total harga, metode pembayaran, dan produk yang dipilih.
// Fungsi ini akan mencari promosi yang sesuai dengan kriteria tertentu, seperti tanggal berlaku, metode pembayaran, dan produk.
// Jika promosi yang sesuai ditemukan, maka manfaat promosi akan diberikan.

TreeNodeEvent* addEvent(TreeNodeEvent* parent, const string& name) {
    TreeNodeEvent* newEvent = new TreeNodeEvent{name, nullptr, {}, Type::Event};

    if (parent) {
        parent->Children.push_back(newEvent);
    }

    return newEvent;
}

TreeNodeEvent* addEventItem(TreeNodeEvent* root, const string& parentEventName, const string& itemName) {
    // Find the parent event
    TreeNodeEvent* parentEvent = nullptr;
    for (TreeNodeEvent* child : root->Children) {
        if (child->eventName == parentEventName && child->type == Type::Event) {
            parentEvent = child;
            break;
        }
    }

    // If the parent event is found, add the event item
    if (parentEvent) {
        // Check if the item exists in the menu
        // Node* menuRoot = parentEvent->menuItem;
        

        // if (menuRoot) {
            // Item exists in the menu, add the event item
            TreeNodeEvent* newEventItem = new TreeNodeEvent{itemName, nullptr, {}, Type::Item};
            parentEvent->Children.push_back(newEventItem);

            cout << "Item added to the event." << endl;
            return newEventItem;
        // } else {
        //     cout << "Error: Item '" << itemName << "' doesn't exist in the menu." << endl;
        //     return nullptr;
        // }
    } else {
        cout << "Error: Parent event '" << parentEventName << "' not found." << endl;
        return nullptr;
    }
}

void displayEventTree(TreeNodeEvent* root, int depth = 0) {
    if (!root) return;

    string indent(depth * 2, ' '); // Create indentation
    cout << indent << root->eventName << endl; // Display category or item name

    for (TreeNodeEvent* child : root->Children) {
        displayEventTree(child, depth + 1);
    }
}

int main() {
    string name;
    Node* root = new Node("Menu");
    TreeNodeEvent* eventroot = new TreeNodeEvent{"Event", nullptr, {}, Type::Event};  // Initialize eventroot properly

    insertall(root);
    //add_category_terminal(root);
    //add_Sub_category_terminal(root);
    //add_Item_terminal(root);
    //deleteNode(root, "Pastry");
    //delete_category_terminal(root);
    //delete_Sub_category_terminal(root);
    //delete_Item_terminal(root);
    //editNode(root, "Teh", "Kopi");
    //edit_category_terminal(root);
    //edit_Sub_category_terminal(root);
    //edit_Item_terminal(root);
    //search_available(root);
    displayTree(root);

    // // ---TEST ADD PROMO---
    // // Menambahkan beberapa promosi untuk diuji
    // AddPromotion(true, 1, 1, 2022, 31, 12, 2022, 2, "Gopay", 50000, "Discount", "Pulsa");
    // AddPromotion(true, 1, 13, 2022, 1, 1, 2023, 1, "Go", 50000, "Discount", "Pul");
    // AddPromotion(true, 1, 1, 2022, 31, 12, 2022, 3, "Gopay", 50000, "Discount", "Pul");
    // AddPromotion(true, 1, 12, 2022, 1, 1, 2023, 1, "Go", 50000, "Discount", "Pul");
    // DisplayPromotions();
    // cout << endl;

    // // --- TEST AVAIL PROMOTION ---
    // // Menguji fungsi ApplyPromotion dengan berbagai skenario untuk melihat apakah promosi yang sesuai diterapkan dengan benar.
    // ApplyPromotion(23, 1, 2022, 100000, "Gopay", "Pul");
    // ApplyPromotion(20, 1, 2022, 100000, "Gopay", "Pul");
    // cout << endl;

    // // // --- TEST EDIT PROMO ---
    // // Mengedit promosi yang sudah ada untuk memperbarui informasi promosi.
    // EditPromotion(4, false, 12, 1, 2022, 31, 12, 2022, 1, "Gopay", 50000, "Discount", "Pulsa");
    // EditPromotion(2, false, 12, 1, 2022, 31, 12, 2022, 2, "Gopay", 50000, "Free Item", "Pulsa");
    // DisplayPromotions();
    // cout << endl;

    // // --- TEST DELETE PROMO ---
    // //  Menghapus promosi yang sudah tidak berlaku atau tidak diperlukan lagi.
    // DeletePromotion(4);
    // DeletePromotion(2);
    // DisplayPromotions();

    addEvent(eventroot, "Lunch");
    addEvent(eventroot, "Breakfast");
    addEvent(eventroot, "Dinner");
    addEventItem(eventroot, "Breakfast", "Burger");

    displayEventTree(eventroot);

    return 0;
}
