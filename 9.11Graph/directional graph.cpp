#include <iostream>
using namespace std;

// Edge class to represent an edge in the adjacency list
class edge 
{
public:
    int data;
    edge* next;
    edge(int value) 
	{
		data=value;
		next=NULL;
	}
};

// Node class to represent a vertex and its adjacency list
class node 
{
public:
    int data;
    edge* head;
    edge* tail;
    node* next;
    node(int value) 
	{
		data=value;
		head=NULL;
		tail=NULL;
		next=NULL;
	}
};

// Graph class to manage vertices and edges
class Graph 
{
private:
    node* head;
    node* tail;

public:
    Graph() 
	{
		head=NULL;
		tail=NULL;
	}

    // Insert a vertex
    void insert_vertex(int data) 
	{
        node* temp = new node(data);
        temp->head = NULL;
        temp->tail = NULL;
        if (head == NULL) 
		{
            temp->next = NULL;
            head = tail = temp;
        } 
		else 
		{
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
    }

    // Check if a vertex exists
    bool check_uname(int data) 
	{
        node* temp = head;
        while (temp != NULL && temp->data != data) 
		{
            temp = temp->next;
        }
        if (temp == NULL || temp->data != data) 
		{
            cout << "Vertex Not Found: " << data << endl;
            return false;
        }
        return true;
    }

    // Add an edge (undirected)
    void add_edge(int vname, int uname) 
	{
        // Check if both vertices exist
        if (!check_uname(vname) || !check_uname(uname)) 
		{
            return;
        }

        // Add edge from vname to uname
        node* temp = head;
        while (temp != NULL && temp->data != vname) 
		{
            temp = temp->next;
        }
        edge* etemp = new edge(uname);
        if (temp->head == NULL) 
		{
            etemp->next = NULL;
            temp->head = temp->tail = etemp;
        } 
		else 
		{
            temp->tail->next = etemp;
            temp->tail = etemp;
            etemp->next = NULL;
        }

        // Add edge from uname to vname (for undirected graph)
        temp = head;
        while (temp != NULL && temp->data != uname) 
		{
            temp = temp->next;
        }
        etemp = new edge(vname);
        if (temp->head == NULL) 
		{
            etemp->next = NULL;
            temp->head = temp->tail = etemp;
        } 
		else 
		{
            temp->tail->next = etemp;
            temp->tail = etemp;
            etemp->next = NULL;
        }
    }

    // Display the adjacency list with labeled vertices
    void display() 
	{
        node* temp = head;
        edge* e;
        cout << "Adjacency List:" << endl;
        while (temp != NULL) 
		{
            // Map numerical data to vertex labels
            char vertexLabel;
            switch (temp->data) 
			{
                case 0: vertexLabel = 'S'; break;
                case 1: vertexLabel = 'A'; break;
                case 2: vertexLabel = 'B'; break;
                case 3: vertexLabel = 'C'; break;
                case 4: vertexLabel = 'D'; break;
                default: vertexLabel = '?'; break;
            }
            cout << vertexLabel << " -> ";

            e = temp->head;
            while (e != NULL) 
			{
                // Map adjacent vertex data to labels
                switch (e->data) 
				{
                    case 0: cout << "S "; break;
                    case 1: cout << "A "; break;
                    case 2: cout << "B "; break;
                    case 3: cout << "C "; break;
                    case 4: cout << "D "; break;
                    default: cout << "? "; break;
                }
                e = e->next;
            }
            temp = temp->next;
            cout << endl;
        }
    }

    // Destructor to free memory
//    void deleteGraph() 
//	{
//        node* temp = head;
//        while (temp != NULL) 
//		{
//            edge* etem = temp->head;
//            while (etem != NULL) 
//			{
//                edge* nextEdge = etem->next;
//                delete etem;
//                etem = nextEdge;
//            }
//            node* nextNode = temp->next;
//            delete temp;
//            temp = nextNode;
//        }
//    }
};

int main() {
    Graph g;

    // Insert vertices (S=0, A=1, B=2, C=3, D=4)
    g.insert_vertex(0); // S
    g.insert_vertex(1); // A
    g.insert_vertex(2); // B
    g.insert_vertex(3); // C
    g.insert_vertex(4); // D

    // Add edges (S connected to A, B, C, D)
    g.add_edge(0, 1); // S-A
    g.add_edge(0, 2); // S-B
    g.add_edge(0, 3); // S-C
    g.add_edge(0, 4); // S-D

    // Display the adjacency list
    g.display();

    return 0;
}
