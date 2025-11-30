/*
You are given an adjacency matrix of an undirected graph.
You must return how many connected components are there.

Each connected component is called a province.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis) {
        vis[node] = 1;

        for (int child : adjLs[node]) {
            if (!vis[child]) {
                dfs(child, adjLs, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int v) {

        vector<int> adjLs[v];

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(v, 0);
        int count = 0;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adjLs, vis);
            }
        }

        return count;
    }
};

int main() {
    int v;
    cout << "Enter number of nodes: ";
    cin >> v;

    vector<vector<int>> adj(v, vector<int>(v));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> adj[i][j];
        }
    }

    Solution obj;               // Create object
    int ans = obj.numProvinces(adj, v); // Call function from main

    cout << "Number of Provinces = " << ans << endl;

    return 0;
}
