#include <iostream>
#include <limits.h>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

void InsertAtEnd(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = 0;
    newNode->next = 0;

    if (*head == 0) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

Node* Maxvalue(Node* head) {
    if (head == 0) {
        return 0;
    }

    Node* maxNode = head;
    int maxVal = 0;
    Node* temp = head;

    while (temp != 0) {
        if (temp->data > maxVal) {
            maxVal = temp->data;
            maxNode = temp;
        }
        temp = temp->next;
    }

    return maxNode;
}

void DeleteNode(Node** head, Node* delNode) {
    if (*head == 0 || delNode == 0) {
        return;
    }

    if (*head == delNode) {
        *head = delNode->next;
    }

    if (delNode->next != 0) {
        delNode->next->prev = delNode->prev;
    }

    if (delNode->prev != 0) {
        delNode->prev->next = delNode->next;
    }

    delete delNode;
}

void PrintList(Node* head) {
    Node* temp = head;
    while (temp != 0) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = 0;

    InsertAtEnd(&head, 10);
    InsertAtEnd(&head, 20);
    InsertAtEnd(&head, 30);
    InsertAtEnd(&head, 40);
    InsertAtEnd(&head, 25);

   cout << "Original List: ";
    PrintList(head);

    Node* maxNode = Maxvalue(head);
    if (maxNode != 0) {
        cout << "Maximum value: " << maxNode->data << endl;
        DeleteNode(&head, maxNode);
    }

    cout << "List after deleting the maximum value: ";
    PrintList(head);

    return 0;
}
