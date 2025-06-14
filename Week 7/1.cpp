#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;

void dijkstra(int start, vector<vector<int>> &graph, vector<int> &dist, vector<int> &parent){
    int n = graph.size();

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start}); // distance, node

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(int v = 0; v < n; v++){
            if(graph[u][v] != 0 && dist[v] > d + graph[u][v]){
                dist[v] = d + graph[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void printPath(int node, vector<int> &parent) {
    if (parent[node] != -1)
        printPath(parent[node], parent);
    cout << node << " ";
}

int main(){
    int n, e;
    cout << "Enter number of location(nodes) and roads(edges): ";
    cin >> n >> e;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter roads (from to distance): ";
        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u][v] = w;
            graph[v][u] = w; // Undirected graph
        }

    int akshayHouse;
    cout << "Enter Akshay's house location (node number): ";
    cin >> akshayHouse;

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dijkstra(akshayHouse, graph, dist, parent);

    cout << "\nShortest distance and path to Akshay's house:\n";
    for (int i = 0; i < n; i++) {
        if (i == akshayHouse) continue;
        cout << "Friend at location " << i << " -> Distance: " << dist[i] << ", Path: ";
        printPath(i, parent);
        cout << endl;
    }

    return 0;
}
