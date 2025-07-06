#include <iostream>
using namespace std;
const int V=5;
class Graph 
{
private:
    int adjMatrix[V][V]; 
public:
    Graph() 
    {
      
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void add_edge(int vname, int uname) 
    {

        adjMatrix[vname][uname] = 1;
        adjMatrix[uname][vname] = 1;
    }
    void display() 
    {
        cout << "Adjacency Matrix (Undirected Graph):" << endl;
        cout << "  S A B C D" << endl;
        for (int i = 0; i < V; i++) 
        {
            char vertexLabel;
            switch (i) 
            {
                case 0: vertexLabel = 'S'; break;
                case 1: vertexLabel = 'A'; break;
                case 2: vertexLabel = 'B'; break;
                case 3: vertexLabel = 'C'; break;
                case 4: vertexLabel = 'D'; break;
                default: vertexLabel = '?'; break;
            }
            cout << vertexLabel << " ";

            for (int j = 0; j < V; j++) 
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() 
{
    Graph g;
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(0, 3); 
    g.add_edge(1, 4); 
    g.add_edge(2, 4); 
    g.add_edge(3, 4); 
    g.display();
    return 0;
}
