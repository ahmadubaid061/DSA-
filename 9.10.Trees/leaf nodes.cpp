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
    Node* insert(int value)
	{
		return insert(root,value);
	}

    int countNodes(Node* node) 
    {
        if (node == NULL) 
        {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int sumNodes(Node* node) 
    {
        if (node == NULL) 
        {
            return 0;
        }
        return node->data + sumNodes(node->left) + sumNodes(node->right);
    }

    void printLeafNodes(Node* node) 
    {
        if (node == NULL) 
        {
            return;
        }
        if (node->left == NULL && node->right == NULL) 
        {
            cout << node->data << " ";
            return;
        }
        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }

    int countLeafNodes(Node* node) 
    {
        if (node == NULL) 
        {
            return 0;
        }
        if (node->left == NULL && node->right == NULL) 
        {
            return 1;
        }
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }
    int countLeafNodes()
    {
    	return countLeafNodes(root);
	}
};

int main() 
{
    BST tree;
    
    tree.root = tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Total number of nodes: " << tree.countNodes(tree.root) << endl;
    cout << "Sum of all node values: " << tree.sumNodes(tree.root) << endl;
    cout << "Leaf nodes: ";
    tree.printLeafNodes(tree.root);
    cout << endl;
    cout << "Number of leaf nodes: " << tree.countLeafNodes() << endl;

    return 0;
}
