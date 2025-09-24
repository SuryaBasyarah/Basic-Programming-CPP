#include <iostream>
// #include <vector>

using namespace std;

struct HashNode {
    int key;
    int value;
};

int A;
int arraySize;

struct HashTable {
    int size;
    HashNode* table;

    HashTable(int tableSize) : size(tableSize) {
        table = new HashNode[tableSize];
        for (int i = 0; i < tableSize; i++)
        {
            
            table[i] = {-1, -1};
        }
    }

    int hashFunction(int key) {
        return (A * key) % size;
    }

    int linearProbe(int index) {
        const int C = 1;
        return (index + C) % size;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        while (table[index].key != -1) {
            index = linearProbe(index);
        }

        table[index].key = key;
        table[index].value = value;
    }

    void display() {
        cout << "Hash Table:\n";
        for (int i = 0; i < size; ++i) {
            if (table[i].key != -1) {
                cout << "Index " << i << ": Key = " << table[i].key << ", Value = " << table[i].value << "\n";
            }
        }
    }

    // Fungsi untuk mencari nilai berdasarkan kunci
    int search(int key) {
        int index = hashFunction(key);

        while (table[index].key != key && table[index].key != -1) {
            index = linearProbe(index);
        }

        if (table[index].key == key) {
            return table[index].value;
        } else {
            return -1; // Kunci tidak ditemukan
        }
    }

    // Fungsi untuk menghapus nilai berdasarkan kunci
    void remove(int key) {
        int index = hashFunction(key);

        while (table[index].key != key && table[index].key != -1) {
            index = linearProbe(index);
        }

        if (table[index].key == key) {
            table[index] = {-1, -1}; // Hapus nilai dengan mengganti slot dengan nilai kosong
        }
    }
};

int main() {
    
    
    cout << "Array size: ";
    cin >> arraySize;
    cout << "A: ";
    cin >> A;
    int values [arraySize] = {66, 47, 87, 90, 126, 140, 145, 153, 177, 285, 393, 395, 467, 566, 620, 735};
    HashTable hashTable(arraySize);

    for (int value : values) {
        hashTable.insert(value, value);
    }

    hashTable.display();

    // Contoh penggunaan fungsi pencarian (search) dan penghapusan (remove)
    int keyToSearch = 145;
    int result = hashTable.search(keyToSearch);

    if (result != -1) {
        cout << "Key " << keyToSearch << " found, value = " << result << "\n";
    } else {
        cout << "Key " << keyToSearch << " not found\n";
    }

    int keyToRemove = 393;
    hashTable.remove(keyToRemove);
    cout << "After removing key " << keyToRemove << ":\n";
    hashTable.display();

    return 0;
}