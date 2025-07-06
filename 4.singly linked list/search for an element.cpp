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
    // Function to search a node and return the complete node
    Node* search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value)
                return temp;  // Return the complete node
            temp = temp->next;
        }
        return 0;  
    }
};

int main() {
    SinglyList list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    int key = 20;
    Node* result = list.search(key);
    if (result)
        cout << "Node found: " << result->data << " (Address: " << result << ")\n";
    else
        cout << key << " not found in the list.\n";
    
    return 0;
}

