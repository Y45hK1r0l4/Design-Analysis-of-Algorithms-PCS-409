
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> bellmanford(int start, vector<vector<int>> &graph, vector<int>& parent) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; ++v) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    if (i == n - 1) {
                        return { -1 };  // Negative cycle detected
                    }
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
    return dist;
}

void printPath(int node, const vector<int>& parent) {
    if (node == -1) return;
    printPath(parent[node], parent);
    cout << node + 1 << " "; 
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];

    int src;
    cout << "Enter source vertex (1-based index): ";
    cin >> src;
    src--;

    vector<int> parent(V, -1);
    vector<int> ans = bellmanford(src, graph, parent);

      if (ans.size() == 1 && ans[0] == -1) {
        cout << "\nNegative weight cycle detected!\n";
        return 0;
    }

    cout << "\nShortest distances and paths from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i + 1 << " : ";
        if (ans[i] == INT_MAX) {
            cout << "Unreachable\n";
        } else {
            printPath(i, parent);
            cout << ": " << ans[i] << "\n";
        }
    }

    return 0;
}
