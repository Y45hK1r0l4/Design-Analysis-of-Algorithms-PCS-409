
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


bool bfs(int start, vector<vector<int>>& graph, vector<int>& visited){
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
  
        for(int neighbour = 0; neighbour < graph.size(); neighbour++){
            if(graph[current][neighbour] == 1){
                if(visited[neighbour] == -1){
                    visited[neighbour] = visited[current] + 1;
                    q.push(neighbour);

                } else if((visited[current] % 2) == (visited[neighbour] % 2)){
                    return false;
                }
            }
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    vector<int> visited(n, -1);
    bool isBipartite = true;

    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            if (!bfs(i, graph, visited)) {
                isBipartite = false;
                break;
            }
        }
    }

    if (isBipartite)
        cout << "Yes Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;

    return 0;
}
