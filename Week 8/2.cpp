
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int x, vector<int>& parent){
    if(parent[x] != x){
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

bool unite(int x, int y, vector<int>& parent, vector<int>& rank){
    x = find(x, parent);
    y = find(y, parent);

    if(x == y) return false;

    if(rank[x] < rank[y]) parent[x] = y;
    else if(rank[x] > rank[y]) parent[y] = x;
    else{
        parent[y] = x;
        rank[x]++;
    }
    return true;
}


int kruskal(int n, vector<vector<int>>& graph) {
    vector<vector<int>> edges;  // Each edge: {weight, u, v}

    // Extract all edges (only upper triangle to avoid duplicates)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j] != 0) {
                edges.push_back({graph[i][j], i, j});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int mstWeight = 0;
    cout << "\nSelected roads (edges in MST):\n";

    for (auto& edge : edges) {
        int w = edge[0], u = edge[1], v = edge[2];
        if (unite(u, v, parent, rank)) {
            mstWeight += w;
        }
    }

    return mstWeight;
}

int main() {
    int V;
    cout << "Enter number of cities: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter roads (adjacency matrix):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int total = kruskal(V, graph);
    cout << "\nMinimum Spanning Weight using Kruskal's: " << total << "\n";

    return 0;
}
