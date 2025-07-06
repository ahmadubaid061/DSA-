#include <iostream>
using namespace std;

// Node class
class Node 
{
public:
    int data;
    Node* next;
    
    Node(int value)
	{
        data = value;
        next = 0;
    }
};

// Singly Linked List class
class SinglyList 
{
public:
    Node* head;

    SinglyList() 
	{ 
	    head = 0; 
	}
};

int main() {
    SinglyList list;
    cout << "Singly Linked List Created!" << endl;
    return 0;
}

