#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = 0;
    }
};

class SinglyList {
public:
    Node* head;

    SinglyList() { head = 0; }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(Node* prev_node, int value) {
        if (prev_node == 0) {
            cout << "The given previous node cannot be NULL\n";
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = prev_node->next;
        prev_node->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyList list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(40);

    cout << "Before Insert: ";
    list.display();

    list.insertAfter(list.head->next, 30);

    cout << "After Insert: ";
    list.display();
    return 0;
}

