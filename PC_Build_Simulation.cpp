#include <iostream>
using namespace std;

int main()
{
    struct
    {
        string name[3] = {"ROG 360mm", "MSI 360mm", "NZXT 240mm"};
        int price[3] = {300, 150, 200};
    } cooler;

    struct
    {
        struct
        {
            string name[3] = {"ROG MAXIMUS Z790", "ROG EXTREME Z790", "MSI PRO Z790"};
            int price[3] = {1700, 1200, 800};
        } lga1700;

        struct
        {
            string name[3] = {"ROG X670-F", "AORUS X670", "ROG X670-E"};
            int price[3] = {800, 850, 1100};
        } am5;
               
    } motherboard;

    struct
    {
        struct
        {
            string name[3] = {"I9 13900K", "I7 13700K", "I5 13500K"};
            int price[3] = {600, 400, 350};
        } intel;
        
        struct 
        {
            string name[3] = {"R7 7700X", "R9 7950X", "R9 7950X3D"};
            int price[3] = {600, 700, 750};
        } amd;
        
    } cpu;

    struct 
    {
        string name[3] = {"RTX 4070", "RTX 4090", "RTX Quadro"};
        int price[3] = {800, 1200, 4500};
    } gpu;

    struct 
    {
        string name[3] = {"NVME M.2 2TB", "NVME M.2 1TB", "NVME M.2 4TB"};
        int price[3] = {150, 80, 280};
    } ssd;

    struct
    {
        string name[3] = {"2X16 DDR4", "2X16 DDR5", "2X32 DDR5"};
        int price[3] = {100, 200, 400};
    } ram;
    
    int select_cpu, select_gpu, select_ssd, select_ram, select_socket, select_motherboard,
        select_cooler;

    cout << "Socket: " << endl;
    cout << "1. LGA 1700" << endl;
    cout << "2. AM5" << endl;
    cout << "Select socket: ";
    cin >> select_socket;
    system("cls");
    //cpu
    switch (select_socket)
    {
    case 1:
        cout << "Processor: " << endl;
        cout << "Name" << "\t\t" << "Price (USD)" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << (i+1) << ". " << cpu.intel.name[i] << "\t" << cpu.intel.price[i] << endl;
        }
        cout << "Select: ";
        cin >> select_cpu;
        cout << endl;
        system("cls");
        break;

    case 2:
        cout << "Processor: " << endl;
        cout << "Name" << "\t\t" << "Price (USD)" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << (i+1) << ". " << cpu.amd.name[i] << "\t" << cpu.amd.price[i] << endl;
        }
        cout << "Select: ";
        cin >> select_cpu;
        cout << endl;
        system("cls");
        break;

    default:
        break;
    }
    //mobo
    switch (select_socket)
    {
    case 1:
        cout << "Motherboard: " << endl;
        cout << "Name" << "\t\t" << "Price (USD)" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << (i+1) << ". " << motherboard.lga1700.name[i] << "\t" << motherboard.lga1700.price[i] << endl;
        }
        cout << "Select: ";
        cin >> select_motherboard;
        cout << endl;
        system("cls");
        break;

    case 2:
        cout << "Motherboard: " << endl;
        cout << "Name" << "\t\t" << "Price (USD)" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << (i+1) << ". " << motherboard.am5.name[i] << "\t" << motherboard.am5.price[i] << endl;
        }
        cout << "Select: ";
        cin >> select_motherboard;
        cout << endl;
        system("cls");
        break;

    default:
        break;
    }
    //gpu
    cout << "Graphics Card: " << endl;
    cout << "Name" << "\t\t" << "Price (USD)" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << (i+1) << ". " << gpu.name[i] << "\t" << gpu.price[i] << endl;
    }
    cout << "Select: ";
    cin >> select_gpu;
    cout << endl;
    system("cls");
    //ssd
    cout << "SSD: " << endl;
    cout << "Name" << "\t\t" << "Price (USD)" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << (i+1) << ". " << ssd.name[i] << "\t" << ssd.price[i] << endl;
    }
    cout << "Select: ";
    cin >> select_ssd;
    cout << endl;
    system("cls");
    //ram
    cout << "RAM: " << endl;
    cout << "Name" << "\t\t" << "Price (USD)" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << (i+1) << ". " << ram.name[i] << "\t" << ram.price[i] << endl;
    }
    cout << "Select: ";
    cin >> select_ram;
    cout << endl;
    system("cls");
    //cooler
    cout << "CPU Cooler: " << endl;
    cout << "Name" << "\t\t" << "Price (USD)" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << (i+1) << ". " << cooler.name[i] << "\t" << cooler.price[i] << endl;
    }
    cout << "Select: ";
    cin >> select_cooler;
    cout << endl;
    system("cls");
    //output
    if (select_socket == 1)
    {
        cout << "Your CPU: \t" << cpu.intel.name[select_cpu-1] << "\tprice: \t" << cpu.intel.price[select_cpu-1] << endl;
    }
    else if (select_socket == 2)
    {
        cout << "Your CPU: \t" << cpu.amd.name[select_cpu-1] << "\tprice: \t" << cpu.amd.price[select_cpu-1] << endl;
    }  
    cout << "Your GPU: \t" << gpu.name[select_gpu-1] << "\tprice: \t" << gpu.price[select_gpu-1] << endl;
    cout << "Your SSD: \t" << ssd.name[select_ssd-1] << "\tprice: \t" << ssd.price[select_ssd-1] << endl;
    cout << "Your RAM: \t" << ram.name[select_ram-1] << "\tprice: \t" << ram.price[select_ram-1] << endl;
    cout << "Your Cooler: \t" << cooler.name[select_cooler-1] << "\tprice: \t" << cooler.price[select_cooler-1] << endl;
    //total price
    int total = 0;
    if (select_socket == 1)
    {
        total += cpu.intel.price[select_cpu-1];
        total += motherboard.lga1700.price[select_motherboard-1];
    }
    else if (select_socket == 2)
    {
        total += cpu.amd.price[select_cpu-1];
        total += motherboard.am5.price[select_motherboard-1];
    }
    total += gpu.price[select_gpu-1] + ssd.price[select_ssd-1] + ram.price[select_ram-1] + cooler.price[select_cooler-1];
    cout << "Total: \t\t\t\t\t" << total;
    cout << endl;
    //payment
    int select_method, balance = 8000;
    cout << "Payment Method: " << endl;
    cout << "1. Cash/Debit" << endl;
    cout << "2. Credit" << endl;
    cout << "Select method: ";
    cin >> select_method;
    switch (select_method)
    {
    case 1:
        if (balance >= total)
        {
            cout << "Payment succeed!" << endl;
            balance -= total;
            cout << "Your balance now: " << balance;
        }
        else
        {
            cout << "Payment declined!" << endl;
        }
        break;
    
    case 2:
        cout << "Credit card declined!" << endl;
        break;
    
    default:
        break;
    }
    return 0;
}