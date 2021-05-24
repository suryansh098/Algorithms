#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

// Dynamic Programming: Problem 3 [All pairs shortest path]
// We need to find shortest from all vertices to all other vertices
// We can also use Dijkstra Algo n-times taking n sources

void printResult(vector<vector<int>> &a) {
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.size(); j++)
            cout<<a[i][j]<<" ";
        cout << endl;
    }
}

void floydWarshall(vector<vector<int>> graph, int n) {
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(graph[i][k] != INF && graph[k][j] != INF)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    printResult(graph);
}


int main() {
    vector<vector<int>> graph =
        {
            {0, 3, INF, 7},
            {8, 0, 2, INF},
            {5, INF, 0, 1},
            {2, INF, INF, 0}
        };

    floydWarshall(graph, graph.size());
}
