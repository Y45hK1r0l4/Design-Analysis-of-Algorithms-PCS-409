#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(int src, vector<vector<pair<int,int>>>& adj, vector<int>& dist){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto& edge : adj[u]){
            int v = edge.first;
            int weight = edge.second;

            if(dist[v] > currDist + weight){
                dist[v] = currDist + weight;
                pq.push({dist[v], v});
            }
        }
    }

}   


int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V); // adjacency list

    cout << "Enter each edge as: u v weight\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    vector<int> dist(V, 1e9); // distance from source
    dijkstra(source, adj, dist);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; ++i)
        cout << "To node " << i << ": " << dist[i] << "\n";

    return 0;

}
