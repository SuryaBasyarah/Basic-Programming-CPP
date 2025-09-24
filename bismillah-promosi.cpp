#include <iostream>
#include <string>

using namespace std;

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
                  int type, int paymenttype, int minimumpayment, string benefit, string product, string paymentMethodName)
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
                   int type, int paymenttype, int minimumpayment, string benefit, string product, string paymentMethodName)
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

int main()
{
    // Example usage of the functions
    AddPromotion(true, 1, 1, 2024, 31, 1, 2024, 1, 2, 100, "10% off", "Product A", PaymentMethod[4]);
    AddPromotion(true, 1, 2, 2024, 28, 2, 2024, 2, 4, 0, "Free Shipping", "Product B", PaymentMethod[1]);
    DisplayPromotions();
    // EditPromotion(1, false, 1, 1, 2024, 15, 1, 2024, 1, 3, 50, "50% off", "Product A", "OVO");
    // DeletePromotion(2);
    // DisplayPromotions();

    return 0;
}
