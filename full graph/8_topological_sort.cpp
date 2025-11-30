/*
🔥 What is Topological Sort?

Topological Sort is an ordering of nodes in a Directed Acyclic Graph (DAG) such that:

👉 Every directed edge u → v comes before v in the ordering.

Meaning:

If task u must happen before v, then u appears earlier in the sorted order.

🟦 Why only for DAG?

Because if the graph has a cycle, then you cannot decide which comes first.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;

    for (int child : adj[node]) {
        if (!vis[child]) {
            dfs(child, adj, vis, st);
        }
    }

    st.push(node); // push after finishing all children
}

vector<int> topoSortDFS(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // directed graph
    }

    vector<int> ans = topoSortDFS(V, adj);

    for (int x : ans) cout << x << " ";
    return 0;
}
