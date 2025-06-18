#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int shortestPathWithKEdges(int u, int v, int k, vector<vector<int>> &graph) {
    if (k == 0 && u == v) return 0;
    if (k == 0) return INF;

    int minWeight = INF;
    int n = graph.size();

    for (int i = 0; i < n; ++i) {
        if (graph[u][i] != 0) {
            int subPath = shortestPathWithKEdges(i, v, k - 1, graph);
            if (subPath != INF) {
                minWeight = min(minWeight, graph[u][i] + subPath);
            }
        }
    }

    return minWeight;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];

    int src, dest, k;
    cin >> src >> dest >> k;

    src--; dest--;  // convert to 0-based index

    int result = shortestPathWithKEdges(src, dest, k, graph);

    if (result == INF)
        cout << "no path of length " << k << " is available" << endl;
    else
        cout << "Weight of shortest path from (" << src + 1 << "," << dest + 1 << ") with " << k << " edges : " << result << endl;

    return 0;
}
