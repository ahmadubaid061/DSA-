#include <iostream>
using namespace std;
const int V=5;
void init(int arr[][V]) 
{
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}


void addEdge(int arr[][V], int i, int j) {
    arr[i][j] = 1;
    arr[j][i] = 1;
}

void printAdjMatrix(int arr[][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        cout << i;
        for (j = 0; j < V; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

// Graph class to manage the adjacency matrix
class Graph 
{
private:
    int adjMatrix[V][V];

public:
    Graph() 
    {
        init(adjMatrix);
    }

    void add_edge(int i, int j) 
    {
        addEdge(adjMatrix, i, j);
    }

    void display() 
    {
        printAdjMatrix(adjMatrix);
    }

    // No destructor needed since no dynamic memory is allocated
    // adjMatrix is a static array, automatically cleaned up
};

int main() 
{
    Graph g;

    // Add edges as specified (S=0, A=1, B=2, C=3, D=4)
    g.add_edge(0, 1); // S-A
    g.add_edge(0, 2); // S-B
    g.add_edge(0, 3); // S-C
    g.add_edge(1, 4); // A-D
    g.add_edge(2, 4); // B-D
    g.add_edge(3, 4); // C-D

    // Display the adjacency matrix
    g.display();

    return 0;
}
