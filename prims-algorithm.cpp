#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

{ { 0, 2, 0, 6, 0 },
  { 2, 0, 3, 8, 5 },
  { 0, 3, 0, 0, 7 },
  { 6, 8, 0, 0, 9 },
  { 0, 5, 7, 9, 0 } }

  0-------1-------2
   \     / \     /
    \   /   \   /
      3-------4
*/

int nearestVertex(vector<int> &dist, vector<bool> &vis) {
    // initialize wt, and vertex
    int wt = INT_MAX, vertex;

    // iterate over all vertices
    for(int i=0; i<dist.size(); i++) {
        // find vertex which is not yet visited and is connected
        // and is having minimum distance
        if(vis[i] == false && dist[i] < wt)
            wt = dist[i], vertex = i;
    }

    // return that vertex
    return vertex;
}

int printMST(vector<int> &parent, vector<vector<int>> &graph) {
    // initialize min cost
    int minCost=0;

    // print edge and weights in MST
    cout<<" Edge \t\t Weight"<<endl;
    for(int i=1; i<graph.size(); i++) {
        cout<<parent[i]<<" -- "<<i<<"\t\t "<<graph[parent[i]][i]<<endl;
        minCost += graph[parent[i]][i];
    }

    // return min cost
    return minCost;
}

int primsAlgorithm(vector<vector<int>> &graph, int n) {
    // consider root = 0
    int root = 0;

    // vector to store visited vertex
    vector<bool> vis(n, false);

    // vector to store distance of only connected edges
    vector<int> distance(n, INT_MAX);

    // vector to store visited edge
    // it stores parent of vertex i at index i
    vector<int> parent(n);

    // since dist of root from root is zero
    distance[root] = 0;

    // MST has no. of edges = no. of vertices - 1
    // so we need to find n-1 edges
    for(int i=0; i<n-1; i++) {
        // find the nearest vertex
        int u = nearestVertex(distance, vis);

        // visit it
        vis[u] = true;

        // iterate over all vertices
        for(int v=0; v<n; v++) {
            // find the connected vertices that are not yet visited
            // and update their distance is vector
            if(graph[u][v] && vis[v] == false && graph[u][v] < distance[v])
                parent[v] = u, distance[v] = graph[u][v];
        }
    }

    return printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                                  { 2, 0, 3, 8, 5 },
                                  { 0, 3, 0, 0, 7 },
                                  { 6, 8, 0, 0, 9 },
                                  { 0, 5, 7, 9, 0 } };

    int minCost = primsAlgorithm(graph, graph.size());
    cout<<"\nMinimum Cost of MST : "<<minCost;
}
