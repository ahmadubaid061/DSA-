#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;

    node(int value, node* nxt = 0) {
        data = value;
        next = nxt;
    }
};

class circularList {
public:
    node* head;
    node* tail;

    circularList() {
        head = tail = 0;
    }

    void insert(int value) {
        node* newNode = new node(value);
        if (head == 0) {
            head = tail = newNode;
            tail->next = head; // Point to itself to form a circle
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Maintain circular link
        }
    }

    void displayList() {
        if (head == 0) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    circularList clist;
    clist.insert(10);
    clist.insert(20);
    clist.insert(30);
    clist.insert(40);

    cout << "Circular Linked List:" << endl;
    clist.displayList();

    return 0;
}

