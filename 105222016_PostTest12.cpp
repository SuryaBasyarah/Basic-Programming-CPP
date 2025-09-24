#include <iostream>
#include <string>
using namespace std;

struct HuffmanNode
{
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Fungsi untuk melakukan pencarian dalam pohon Huffman
bool searchHuffmanTree(HuffmanNode* root, char target, string& path)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    if (searchHuffmanTree(root->left, target, path))
    {
        path = '0' + path;
        return true;
    }

    if (searchHuffmanTree(root->right, target, path))
    {
        path = '1' + path;
        return true;
    }

    return false;
}

int main()
{
    system("cls");

    cout << "Pencarian dalam pohon Huffman :" << endl;

    HuffmanNode* root = new HuffmanNode('$', 0); 
    root->left = new HuffmanNode('A', 6);
    root->right = new HuffmanNode('$', 15);
    root->right->left = new HuffmanNode('$', 7);
    root->right->right = new HuffmanNode('M', 8);
    root->right->left->left = new HuffmanNode('I', 3);
    root->right->left->right = new HuffmanNode('T', 4);
    root->right->right->left = new HuffmanNode('U', 4);
    root->right->right->right = new HuffmanNode('D', 4);

    // Pencarian setiap karakter
    string input = "MATEMATIKAITUMUDAH";
    for (char target : input)
    {
        string path;
        bool found = searchHuffmanTree(root, target, path);

        if (found)
        {
            cout << "Karakter '" << target << "' ditemukan dalam pohon Huffman. Path: " << path << endl;
        }
        else
        {
            cout << "Karakter '" << target << "' tidak ditemukan dalam pohon Huffman." << endl;
        }
    }
    
    delete root;

    return 0;
}