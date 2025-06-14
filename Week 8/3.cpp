#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int maxst(int n, vector<vector<int>>& graph){
    vector<int> key(n, INT_MIN);
    vector<bool> inMST(n, false);
    int maxWeight = 0;

    priority_queue<pair<int, int>> pq;
    key[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(inMST[u])continue;
        inMST[u] = true;
        maxWeight += key[u];

        for(int v = 0; v < n; v++){
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] > key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
            }
        }
    }
    return maxWeight;
}


int main() {
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];

    cout << "Maximum Spanning Weight: " << maxst(V, graph) << endl;

    return 0;
}
