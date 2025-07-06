#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;  
        right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value); 
    }

    if (value < root->data) {
        root->left = insert(root->left, value); 
    } else {
        root->right = insert(root->right, value); 
    }

    return root;
}

// Inorder Traversal
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Preorder Traversal: 
void preorderTraversal(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

bool search(Node* root, int key) {
    if (root == NULL) {
        return false; 
    }

    if (root->data == key) {
        return true; 
    }

    if (key < root->data) {
        return search(root->left, key); 
    } else {
        return search(root->right, key); 
    }
}

int height(Node* root) {
    if (root == NULL) {
        return 0; 
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}


int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}


void deleteTree(Node*& root) {
    if (root == NULL) return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
    root = NULL;
}

int main() {
    Node* root = NULL;

    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    int key = 40;
    cout << "Searching for " << key << ": ";
    if (search(root, key)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    cout << "Height of tree: " << height(root) << endl;
    cout << "Total number of nodes: " << countNodes(root) << endl;

    
    deleteTree(root);

    return 0;
}

