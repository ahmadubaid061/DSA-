#include <iostream>
#include <stack>
using namespace std;
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
class SinglyList 
{
public:
    Node* head;

    SinglyList() 
	{ 
	    head = 0; 
	}

    void insertAtTail(int value) 
	{
        Node* newNode = new Node(value);
        if (!head) 
		{
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) 
		{
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void displayReverse() 
	{
        stack<int> s;
        Node* temp = head;
        while (temp) 
		{
            s.push(temp->data);
            temp = temp->next;
        }
        while (!s.empty()) 
		{
            cout << s.top() << " -> ";
            s.pop();
        }
        cout << "NULL\n";
    }
};
int main() 
{
    SinglyList list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    cout << "Reverse Linked List: ";
    list.displayReverse();
    return 0;
}

