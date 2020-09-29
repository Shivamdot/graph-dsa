#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    int node_size;
    vector<vector<int> > adj;
    // Constructor
    Graph(int node_size_val);
    // Add edges to the graph
    void addEdge(int node1, int node2);
    // Traverse the graph
    void traverse();
    // Display the matrix
    void display();
};

Graph::Graph(int node_size_val) {
    node_size = node_size_val+1;
    // Initialising andjency matrix
    for(int i=0; i<node_size; i++) {
        adj.push_back(vector<int> (node_size));
    }
}

void Graph::addEdge(int node1, int node2) {
    adj[node1][node2] = 1;
    adj[node2][node1] = 1;
}

void Graph::traverse() {
    for(int i=1; i<node_size; i++) {
        for(int j=1; j<node_size; j++) {
            if(adj[i][j] == 1) {
                cout<<i<<" -> "<<j<<endl;
            }
        }
    }
}

void Graph::display() {
    for(int i=1; i<node_size; i++) {
        for(int j=1; j<node_size; j++) {
            cout << adj[i][j]<<' ';
            }
        cout<<endl;
    }
}

int main()
{
    int n,e;

    cout<<"Enter number of nodes: ";
    cin>>n;

    Graph g(n);

    cout<<"Enter number of edges: ";
    cin>>e;

    cout<<"Enter edges:"<<endl;

    for(int i=0; i<e; i++) {
        int n1,n2;
        cin>>n1>>n2;
        g.addEdge(n1, n2);
    }

    cout<<endl<<"Graph Traversal: "<<endl;
    g.traverse();

    cout<<endl<<"Matrix: "<<endl;
    g.display();

    return 0;
}
