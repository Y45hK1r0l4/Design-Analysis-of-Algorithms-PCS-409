#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> graph, vector<int>& visited){
    visited[node] = 1; 

    for(int v = 0; v < graph.size(); v++){
        if(graph[node][v] == 1){
            if(visited[v] == 0){
                if(dfs(v, graph, visited)) return true;
            }else if(visited[v] == 1){
                return true;
            }
        }
    }

    visited[node] = 2;  
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    vector<int> state(n, 0); 

    for (int i = 0; i < n; ++i) {
        if (state[i] == 0) {
            if (dfs(i, graph, state)) {
                cout << "Yes Cycle Exists" << endl;
                return 0;
            }
        }
    }

    cout << "No Cycle Exists" << endl;
    return 0;
}
