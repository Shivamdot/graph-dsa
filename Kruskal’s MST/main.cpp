#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    // variables
    int node_size;
    vector< vector<int> > adj;
    vector<pair<int, pair<int, int> > > nodes;

    // Constructor
    Graph(int node_size_val);
    // Add edges to the graph
    void addEdge(int node1, int node2, int weight);
    // Cyclic Check
    int isCyclic(int node1, int node2);
    // kruskal's MST
    int kruskalMST();
};

Graph::Graph(int node_size_val) {
    node_size = node_size_val+1;
    // Initialising andjency matrix
    for(int i=0; i<node_size; i++) {
        adj.push_back(vector<int> (node_size));
    }
}

void Graph::addEdge(int node1, int node2, int weight) {
    nodes.push_back(make_pair(weight, make_pair(node1, node2)));
}

// using BFS to check is there a cycle or not.
int Graph::isCyclic(int node1, int node2) {  // returns either 1 or 0
    queue<int> q;
    vector<int> visited(node_size);

    q.push(node1);
    visited[node1] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(node == node2){
            return 1;
        }
        for(int i=1; i<node_size; i++) {
            if(visited[i] == 0 && adj[node][i] == 1) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    return 0;
}

int Graph::kruskalMST() {
    int cost=0;

    sort(nodes.begin(), nodes.end());

    for(int i=0; i<nodes.size(); i++) {
        int w = nodes[i].first;
        int n1 = nodes[i].second.first;
        int n2 = nodes[i].second.second;
        if(!isCyclic(n1, n2)) { // Not Cyclic
            adj[n1][n2] = 1;
            adj[n2][n1] = 1;
            cost += w;
        }
    }

    return cost;
}

int main()
{
    int n,e;

    cout<<"Enter number of nodes: ";
    cin>>n;

    Graph g(n);

    cout<<"Enter number of edges: ";
    cin>>e;

    cout<<"Enter edges with their weights:"<<endl;

    for(int i=0; i<e; i++) {
        int n1,n2,w;
        cin>>n1>>n2>>w;
        g.addEdge(n1, n2, w);
    }

    cout<<endl<<"Minimum Cost for the given Graph is: "<<g.kruskalMST();

    return 0;
}
