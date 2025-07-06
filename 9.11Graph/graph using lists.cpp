#include <iostream>
using namespace std;

class edge {
public:
    int data;
    edge* next;
    edge(int value) : data(value), next(NULL) {}
};


class node {
public:
    int data;
    edge* head;
    edge* tail;
    node* next;
    node(int value) : data(value), head(NULL), tail(NULL), next(NULL) {}
};

class Graph {
private:
    node* head;
    node* tail;

public:
    Graph() : head(NULL), tail(NULL) {}

    void insert_vertex(int data) {
        node* temp = new node(data);
        temp->head = NULL;
        temp->tail = NULL;
        if (head == NULL) {
            temp->next = NULL;
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
    }

    bool check_uname(int data) {
        node* temp = head;
        while (temp != NULL && temp->data != data) {
            temp = temp->next;
        }
        if (temp == NULL || temp->data != data) {
            cout << "Vertex Not Found: " << data << endl;
            return false;
        }
        return true;
    }

   
    void add_edge(int vname, int uname) {
       
        if (!check_uname(vname) || !check_uname(uname)) {
            return;
        }

   
        node* temp = head;
        while (temp != NULL && temp->data != vname) {
            temp = temp->next;
        }
        edge* etemp = new edge(uname);
        if (temp->head == NULL) {
            etemp->next = NULL;
            temp->head = temp->tail = etemp;
        } else {
            temp->tail->next = etemp;
            temp->tail = etemp;
            etemp->next = NULL;
        }

        temp = head;
        while (temp != NULL && temp->data != uname) {
            temp = temp->next;
        }
        etemp = new edge(vname);
        if (temp->head == NULL) {
            etemp->next = NULL;
            temp->head = temp->tail = etemp;
        } else {
            temp->tail->next = etemp;
            temp->tail = etemp;
            etemp->next = NULL;
        }
    }


    void display() {
        node* temp = head;
        edge* etem;
        cout << "Adjacency List:" << endl;
        while (temp != NULL) {
            etem = temp->head;
            cout << temp->data << " -> ";
            while (etem != NULL) {
                cout << etem->data << " ";
                etem = etem->next;
            }
            temp = temp->next;
            cout << endl;
        }
    }

    ~Graph() {
        node* temp = head;
        while (temp != NULL) {
            edge* etem = temp->head;
            while (etem != NULL) {
                edge* nextEdge = etem->next;
                delete etem;
                etem = nextEdge;
            }
            node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    Graph g;

    g.insert_vertex(0);
    g.insert_vertex(1);
    g.insert_vertex(2);
    g.insert_vertex(3);
    g.insert_vertex(4);

    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(3, 4);

    g.display();

    return 0;
}
