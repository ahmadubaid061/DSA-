#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int value) 
	{
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST 
{
public:
    Node* root;

    BST() 
	{
        root = NULL;
    }

    Node* insert(Node* node, int value) 
	{
        if (node == NULL) 
		{
            return new Node(value);
        }
        if (value < node->data) 
		{
            node->left = insert(node->left, value);
        } else 
		{
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value) 
	{
        root = insert(root, value);
    }
    
    int countNodes(Node* node) 
	{
        if (node == NULL) 
		{
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countNodes() 
	{
        return countNodes(root);
    }

    int sumNodes(Node* node) 
	{
        if (node == NULL) 
		{
            return 0;
        }
        return node->data + sumNodes(node->left) + sumNodes(node->right);
    }

    int sumNodes() 
	{
        return sumNodes(root);
    }
};

int main() 
{
    BST tree;
    
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Total number of nodes: " << tree.countNodes() << endl;
    cout << "Sum of all node values: " << tree.sumNodes() << endl;

    return 0;
}
