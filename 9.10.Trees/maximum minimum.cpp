#include <iostream>
using namespace std;
struct Node {
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
	    } 
		else 
		{
	        node->right = insert(node->right, value);
	    }
	    return node;
	}
	Node* insert(int value)
	{
		return insert(root,value);
	}
	int findMin(Node* node) 
	{
	    if (node == NULL) 
		{
	        cout << "Tree is empty";
	    }
	    Node* current = node;
	    while (current->left != NULL) 
		{
	        current = current->left;
	    }
	    return current->data;
	}
	int findMin()
	{
		return findMin(root);
	}
	int findMax(Node* node) 
	{
	    if (node == NULL) 
		{
	        cout << "Tree is empty";
	    }
	    Node* current = node;
	    while (current->right != NULL) 
		{
	        current = current->right;
	    }
	    return current->data;
	}
	int findMax()
	{
		return findMax(root);
	}
};
int main() {
    BST tree;
    tree.root = tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    cout << "Minimum value is: " << tree.findMin() << endl;
    cout << "Maximum value is: " << tree.findMax() << endl;
    return 0;
}
