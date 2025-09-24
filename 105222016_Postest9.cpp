#include <iostream>
using namespace std;

struct Node
{
	string data;
	struct Node *next;
	struct Node *child;
};

// Creating new Node
Node* newNode(string data)
{
	Node *newNode = new Node;
	newNode->next = newNode->child = NULL;
	newNode->data = data;
	return newNode;
}

// Adds a sibling to a list with starting with n
Node *addSibling(Node *n, string data)
{
	if (n == NULL)
		return NULL;

	while (n->next)
		n = n->next;

	return (n->next = newNode(data));
}

// Add child Node to a Node
Node *addChild(Node * n, string data)
{
	if (n == NULL)
		return NULL;

	// Check if child list is not empty.
	if (n->child)
		return addSibling(n->child, data);
	else
		return (n->child = newNode(data));
}

// Traverses tree in depth first order
void traverseTree(Node * root)
{
	if (root == NULL)
		return;

	while (root)
	{
		cout << " " << root->data;
		if (root->child)
			traverseTree(root->child);
		root = root->next;
	}
}

//Driver code

int main()
{
	// Left child right sibling
	/* surya
	* |
	* Akira    ->   Baruna          ->             Sheva           ->    Dandunh
	* |               |                              |                      |
    * Alghif -> L	 Jia -> Ferdinand -> Humam	  Athirah -> Ekal         Manput -> Febry -> Dhevan
	*/
	Node *root = newNode("Surya");
	Node *n1 = addChild(root, "Akira"); //C1
	Node *n2 = addChild(n1, "Alghif");
	Node *n3 = addChild(n1, "L");
	Node *n4 = addChild(root, "Baruna"); //C2
	Node *n5 = addChild(n4, "Jia");
	Node *n6 = addChild(n4, "Ferdinand");
	Node *n7 = addChild(n4, "Humam");
	Node *n8 = addChild(root, "Sheva"); //C3
    Node *n9 = addChild(n8, "Athirah");
    Node *n10 = addChild(n8, "Ekal");
    Node *n11 = addChild(root, "Dandunh"); //C4
    Node *n12 = addChild(n11, "Manput");
    Node *n13 = addChild(n11, "Febry");
    Node *n14 = addChild(n11, "Dhevan");
	traverseTree(root);
	return 0;
}