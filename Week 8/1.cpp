
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int prim(int n, vector<vector<int>>& graph){
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMst(n, false);
    int result = 0;

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0,0});   // Weight, vertex

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(inMst[u]) continue;
        inMst[u] = true;
        result += key[u];

        for(int v = 0; v < n; v++){
            if (graph[u][v] != 0 && !inMst[v] && graph[u][v] < key[v])
                key[v] = graph[u][v]; 
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    return result;
}

int main() {
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter roads (from to distance): ";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int totalCost = prim(V, graph);
    cout << "\nMinimum Spanning Weight using Prim's: " << totalCost << "\n";

    return 0;
}
