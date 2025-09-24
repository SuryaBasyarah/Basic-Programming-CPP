#include <iostream>
using namespace std;

int tree[] = {10, 15, 20, 25, 30, 5};


int sizetree = sizeof(tree)/sizeof(tree[0]);

void heapify(int tree[], int size, int max)
{
    int maxtree = max;
    int left = 2 * max + 1;
    int right = 2 * max + 2;

    if (left < size && tree[left] > tree[maxtree])
    {
        maxtree = left;
    }
    if (right < size && tree[right] > tree[maxtree])
    {
        maxtree = right;
    }
    if (maxtree != max)
    {
        int temp = tree[max];
        tree[max] = tree[maxtree];
        tree[maxtree] = temp;
        heapify(tree, size, maxtree);
    }
}

void heapsort(int tree[], int size)
{
    for (int i = size/2-1; i >= 0; i--)
        heapify(tree, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        int temp = tree[0];
        tree[0] = tree[i];
        tree[i] = temp;
        heapify(tree, size, 0);
    }
}

void printtree(int tree[], int size)
{
    for (int index = 0; index < size; index++)
        cout << tree[index] << ", ";
    cout << endl;
}

void traverse(int tree[], int size, int index, int depth = 0)
{
    for (int i = 0; i < depth; i++)
        cout << "   ";

    cout << tree[index] << endl;

    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size)
        traverse(tree, size, leftChild, depth + 1);

    if (rightChild < size)
        traverse(tree, size, rightChild, depth + 1);
}

int main()
{
    cout << "Before sorting: ";
    printtree(tree, sizetree);
    traverse(tree, sizetree, 0);
    heapsort(tree, sizetree);
    cout << endl;

    cout << "\nAfter sorting: ";
    printtree(tree, sizetree);
    traverse(tree, sizetree, 0);

    return 0;
}
