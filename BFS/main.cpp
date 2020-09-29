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
    // BFS function
    void bfs();
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

void Graph::bfs() {
    vector<int > visited(node_size);
    queue<int> q;

    int pos=1;

    q.push(pos);
    visited[pos] = 1;

    cout<<"\nThe BFS is:"<<endl;

    while(!q.empty()) {
        for(int i=1; i<node_size; i++) {
            if(adj[pos][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
        cout<<pos<<" ";
        q.pop();
        pos = q.front();
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

    g.bfs();

    return 0;
}
