//undirected
#include <bits/stdc++.h>
using namespace std;

void bfshelper(vector<int> adj[], vector<int>& ans, int node, vector<int>& visited) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for (auto i : adj[frontnode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

// Function to return Breadth First Traversal of the given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bfshelper(adj, ans, i, visited);
        }
    }
    return ans;
}

int main() {
    int V = 5; // Number of vertices
    int E = 4; // Number of edges
    vector<int> adj[V];

    // Input the graph edges for an undirected graph
    adj[0] = {1, 2, 3};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    // Perform BFS traversal
    vector<int> bfsResult = bfsOfGraph(V, adj);

    // Print the BFS traversal result
    cout << "BFS traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}



//directed 



#include <bits/stdc++.h>
using namespace std;

void bfshelper(vector<int> adj[], vector<int>& ans, int node, vector<int>& visited) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for (auto i : adj[frontnode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

// Function to return Breadth First Traversal of the given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> visited(V, 0);
    bfshelper(adj, ans, 0, visited);
    return ans;
}

int main() {
    int V = 5; // Number of vertices
    int E = 4; // Number of edges
    vector<int> adj[V];

    // Input the graph edges
    adj[0] = {1, 2, 3};
    adj[2] = {4};

    // Perform BFS traversal
    vector<int> bfsResult = bfsOfGraph(V, adj);

    // Print the BFS traversal result
    cout << "BFS traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


