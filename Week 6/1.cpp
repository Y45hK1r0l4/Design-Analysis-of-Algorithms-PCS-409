#include <iostream>
#include <vector>
using namespace std;

void dfs(int current, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[current] = true;

    for (int i = 0; i < graph.size(); i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfs(i, visited, graph);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int source, dest;
    cin >> source >> dest;

    source--;
    dest--;

    vector<bool> visited(n, false);
    dfs(source, visited, graph);

    if (visited[dest])
        cout << "Yes Path Exists" << endl;
    else
        cout << "No Such Path Exists" << endl;

    return 0;
}
