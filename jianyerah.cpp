#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

struct Node {
    string name; // Nama kategori atau item
    float price; // Harga item
    int stock; // Jumlah stok item
    Node* leftChild; // Anak kiri
    Node* rightSibling; // Anak kanan

    // Konstruktor untuk kategori (tidak ada harga dan stok)
    explicit Node(const string& name) {
        this->name = name;
        this->price = 0;
        this->stock = 0;
        this->leftChild = nullptr;
        this->rightSibling = nullptr;
    }

    // Konstruktor untuk item (ada harga dan stok)
    Node(const string& name, float price, int stock) {
        this->name = name;
        this->price = price;
        this->stock = stock;
        this->leftChild = nullptr;
        this->rightSibling = nullptr;
    }

    // Memeriksa apakah node merupakan kategori atau item
    bool isItem() const {
        return this->price != 0 || this->stock != 0;
    }
};

Node* addCategory_n_Sub(Node* parent, const string& name);
Node* addItem(Node* parent, const string& name, float price, int stock);
Node* findNode(Node* root, const string& name);
void editNode(Node* root, const string& name, const string& newName, float newPrice, int newStocks);
void displayTree(Node* root, int depth = 0);
void deleteTree(Node* root);
void fillMenu(Node* root, const vector<tuple<string, vector<pair<string, vector<tuple<string, float, int>>>>>>& menuData);
void insertall(Node* root);
//=========================================
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

const string PaymentMethod[9] = {"MoePay", "Debit", "Credit", "Cash", "Gopay", "LinkAja", "Dana", "Ovo", "ShopeePay"};

PromotionNode *head = nullptr;
int numberOfPromotions = 0;

void AddPromotion(bool status,
                  int startDate_day, int startDate_month, int startDate_year,
                  int endDate_day, int endDate_month, int endDate_year,
                  int type, int paymenttype, int minimumpayment, string benefit, string product);
void EditPromotion(int selectedpromotion, bool status,
                   int startDate_day, int startDate_month, int startDate_year,
                   int endDate_day, int endDate_month, int endDate_year,
                   int type, int paymenttype, int minimumpayment, string benefit, string product);
void DeletePromotion(int selectedpromotion);
void DisplayPromotions();
//=======================================
enum Type { Item, Event };

struct TreeNodeEvent
{
    string eventName;
    Node* menuItem;
    TreeNodeEvent *Child;
    TreeNodeEvent *Sibling;
    Type type;

};

TreeNodeEvent* addEvent(TreeNodeEvent* parent, const string& name);
TreeNodeEvent* addEventItem(TreeNodeEvent* root, const string& parentEventName, const string& itemName);
void displayEventTree(TreeNodeEvent* root, int depth = 0);


int main() {
    Node* root = new Node("Menu");
    TreeNodeEvent* eventroot = new TreeNodeEvent{"Event", nullptr, nullptr, nullptr, Type::Event};  // Initialize eventroot properly


    insertall(root);
    // Display the tree to verify
    //displayTree(root);
    // Node* tambahevent = addCategory_n_Sub (root, "test");
    // Node* tambahevent2 = addCategory_n_Sub (root->leftChild, "test2");
    // displayTree(root);

    // AddPromotion(true, 1, 1, 2024, 31, 1, 2024, 1, 2, 100, "Discount 10%", "Product A");
    // AddPromotion(true, 1, 2, 2024, 28, 2, 2024, 2, 4, 0, "Free Shipping", "Product B");
    // DisplayPromotions();

    addEvent(eventroot, "Lunch");
    addEvent(eventroot, "Breakfast");
    addEvent(eventroot, "Dinner");
    addEventItem(eventroot, "Breakfast", "test");

    displayEventTree(eventroot);
    return 0;
}


// Fungsi untuk menambahkan kategori baru
Node* addCategory_n_Sub(Node* parent, const string& name) {
    if (!parent) return nullptr;

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

// Fungsi untuk menambahkan item baru
Node* addItem(Node* parent, const string& name, float price, int stock) {
    if (!parent) return nullptr;

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
    if (!root) return nullptr;

    if (root->name == name) return root;

    Node* foundNode = findNode(root->leftChild, name);
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

// Fungsi untuk mengganti isi dari kategori atau item
void editNode(Node* root, const string& name, const string& newName, float newPrice = 0, int newStock = 0) {
    Node* node = findNode(root, name);
    if (node != nullptr){
        if (node->isItem()) {
            node->name = newName;
            node->price = newPrice;
            node->stock = newStock;
        } else {
            node->name = newName;
        }
    } else {
        cout << "Node tidak ditemukan" << endl;
    }
}

// Fungsi untuk menampilkan tree
void displayTree(Node* root, int depth) {
    if (!root) return;

    string indent(depth * 2, ' '); // Membuat indentasi
    cout << indent << root->name << endl; // Menampilkan nama kategori atau item

    if (root->leftChild) {
        displayTree(root->leftChild, depth + 1);
    }

    if (root->rightSibling) {
        displayTree(root->rightSibling, depth);
    }
}

// Fungsi untuk menghapus tree
void deleteTree(Node* root) {
    if (!root) return;

    if (root->leftChild) {
        deleteTree(root->leftChild);
    }

    if (root->rightSibling) {
        deleteTree(root->rightSibling);
    }

    delete root;
}

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

void insertall(Node* root){
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

void AddPromotion(bool status,
                  int startDate_day, int startDate_month, int startDate_year,
                  int endDate_day, int endDate_month, int endDate_year,
                  int type, int paymenttype, int minimumpayment, string benefit, string product)
{
    if (endDate_year < startDate_year || (endDate_year == startDate_year && endDate_month < startDate_month) || (endDate_year == startDate_year && endDate_month == startDate_month && endDate_day < startDate_day))
    {
        cout << "Error: End date cannot be earlier than start date!" << endl;
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
    newNode->PromotionType = type;
    newNode->PaymentMethod = PaymentMethod[paymenttype];
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

void EditPromotion(int selectedpromotion, bool status,
                   int startDate_day, int startDate_month, int startDate_year,
                   int endDate_day, int endDate_month, int endDate_year,
                   int type, int paymenttype, int minimumpayment, string benefit, string product)
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

    current->Status = status;
    current->StartDate.day = startDate_day;
    current->StartDate.month = startDate_month;
    current->StartDate.year = startDate_year;
    current->EndDate.day = endDate_day;
    current->EndDate.month = endDate_month;
    current->EndDate.year = endDate_year;
    current->PromotionType = type;
    current->PaymentMethod = PaymentMethod[paymenttype];
    current->MinimumPayment = minimumpayment;
    current->Product = product;
    current->Benefit = benefit;

    cout << "Promotion edited." << endl;
}

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

void DisplayPromotions()
{
    PromotionNode *current = head;
    int index = 1;

    while (current != nullptr)
    {
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

        current = current->next;
        index++;
    }
}

TreeNodeEvent* addEvent(TreeNodeEvent* parent, const string& name) {
    TreeNodeEvent* newEvent = new TreeNodeEvent{name, nullptr, nullptr, nullptr, Type::Event};

    if (parent) {
        if (!parent->Child) {
            parent->Child = newEvent;
        } else {
            // cout << "test2";
            TreeNodeEvent* sibling = parent->Child;
            while (sibling->Sibling) {
                sibling = sibling->Sibling;
            }
            sibling->Sibling = newEvent;
        }
    }

    return newEvent;
}

TreeNodeEvent* addEventItem(TreeNodeEvent* root, const string& parentEventName, const string& itemName) {
    // Find the parent event
    TreeNodeEvent* parentEvent = nullptr;
    TreeNodeEvent* current = root->Child;

    while (current) {
        if (current->eventName == parentEventName && current->type == Type::Event) {
            parentEvent = current;
            break;
        }
        current = current->Sibling;
    }

    // If the parent event is found, add the event item
    if (parentEvent) {
        TreeNodeEvent* newEventItem = new TreeNodeEvent{itemName, nullptr, nullptr, nullptr, Type::Item};

        if (!parentEvent->Child) {
            parentEvent->Child = newEventItem;
        } else {
            TreeNodeEvent* sibling = parentEvent->Child;
            while (sibling->Sibling) {
                sibling = sibling->Sibling;
            }
            sibling->Sibling = newEventItem;
        }

        return newEventItem;
    } else {
        cout << "Parent event not found: " << parentEventName << endl;
        return nullptr;
    }
}



void displayEventTree(TreeNodeEvent* root, int depth) {
    if (!root) return;

    string indent(depth * 2, ' '); // Membuat indentasi
    cout << indent << root->eventName << endl; // Menampilkan nama kategori atau item

    if (root->Child) {
        displayEventTree(root->Child, depth + 1);
    }

    if (root->Sibling) {
        displayEventTree(root->Sibling, depth);
    }
}









