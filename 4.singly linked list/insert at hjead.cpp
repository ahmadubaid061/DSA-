#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
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
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    cout << "Linked List: ";
    list.display();
    return 0;
}

