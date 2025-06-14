
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& graph, int V){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(graph[i][k] < INF && graph[k][j] < INF){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                } 
            }
        }
    }
}


int main() {
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            string val;
            cin >> val;
            if (val == "INF")
                graph[i][j] = INF;
            else
                graph[i][j] = stoi(val);    // string to integer
        }
    }

    // Run Floyd-Warshall
    floydWarshall(graph, V);

    // Output the shortest distance matrix
    cout << "Shortest Distance Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (graph[i][j] == INF)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
