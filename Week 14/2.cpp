#include <iostream>
#include <vector>
using namespace std;

// Depth-First Search function
void dfs(int v, const vector<vector<int>>& matrix, vector<bool>& visited) {
    visited[v] = true;
    for (int u = 0; u < matrix[v].size(); ++u) {
        if (matrix[v][u] == 1 && !visited[u]) {
            dfs(u, matrix, visited);
        }
    }
}

// Function to find mother vertex
int findMotherVertex(const vector<vector<int>>& matrix, int n) {
    vector<bool> visited(n, false);
    int candidate = -1;

    // Step 1: Find candidate mother vertex
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, matrix, visited);
            candidate = i;
        }
    }

    // Step 2: Verify candidate
    fill(visited.begin(), visited.end(), false);
    dfs(candidate, matrix, visited);

    // Step 3: Check if all vertices were visited
    for (bool v : visited) {
        if (!v) return -1;  // No mother vertex
    }

    return candidate;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the adjacency matrix (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int mother = findMotherVertex(matrix, n);
    if (mother == -1)
        cout << "No mother vertex exists." << endl;
    else
        cout << "Mother vertex is: " << mother << endl;

    return 0;
}
