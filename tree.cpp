#include <iostream>
using namespace std;

struct tree
{
    int number;
    tree *right, *left, *parent;
};

tree *root, *newnode;

void createtree(int data)
{
    root = new tree();
    root->number = data;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
}

void insertleft(tree *node, int data)
{
    newnode = new tree();
    newnode->number = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = node;
    node->left = newnode;
}

void insertright(tree *node, int data)
{
    newnode = new tree();
    newnode->number = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = node;
    node->right = newnode;
}

void preorder(tree *temp = root)
{
    if (temp != NULL)
    {
        cout << temp->number << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(tree *temp = root)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->number << " ";
        inorder(temp->right);
    }
}

void postorder(tree *temp = root)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->number << " ";
    }
}