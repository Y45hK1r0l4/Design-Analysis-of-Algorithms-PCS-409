
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> bellmanford(int start, vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; ++v) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    if (i == n - 1) {
                        return { -1 };  
                    }
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    return dist;
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

    vector<int> ans = bellmanford(src, graph);

    if (ans.size() == 1 && ans[0] == -1) {
        cout << "Negative weight cycle detected!" << endl;
        return 0;
    }

    cout << "\nShortest distances from vertex " << src + 1 << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i + 1 << " : ";
        if (ans[i] == INT_MAX)
            cout << "Unreachable";
        else
            cout << ans[i];
        cout << endl;
    }

    return 0;
}
