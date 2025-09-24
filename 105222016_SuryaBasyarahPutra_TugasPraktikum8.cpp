#include <iostream>
using namespace std;

struct tree
{
    char number;
    tree *right, *left, *parent;
};

tree *root, *newnode;

void createtree(char data)
{
    root = new tree();
    root->number = data;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
}

void insertleft(tree *node, char data)
{
    newnode = new tree();
    newnode->number = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = node;
    node->left = newnode;
}

void insertright(tree *node, char data)
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

void insertelement(tree *parent, char data)
{
    if (root == NULL)
    {
        createtree(data);
    }
    else
    {
        if ((int)parent->number > (int)data)
        {
            if (parent->left != NULL)
            {
                parent = parent->left;
                insertelement(parent, data);
            }
            else
            {
                insertleft(parent, data);
            }
        }
        else if ((int)parent->number < (int)data)
        {
            if (parent->right != NULL)
            {
                parent = parent->right;
                insertelement(parent, data);
            }
            else
            {
                insertright(parent, data);
            }
        }
    }
}

int main()
{
    createtree('J');
    insertelement(root, 'F');
    insertelement(root, 'M');
    insertelement(root, 'A');
    insertelement(root, 'G');
    insertelement(root, 'K');
    insertelement(root, 'N');
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);


    return 0;
}