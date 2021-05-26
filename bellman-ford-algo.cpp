#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX

// Dynamic Programming: Problem 5 [Bellman Ford Algo]
// Single Source Shortest Path Algorithm
// Unlike Dijstra's Algo, this algo works when paths are negative.

// class defining an edge
class Edge {
    public:
    int u;
    int v;
    int wt;
};

// this function prints the minimum distance of all vertices from src
void printDistances(vector<int> &distance) {
    cout<<"Vertex \t Distance from Source"<<endl;
    for(int i=0; i<distance.size(); i++) {
        cout<<i<<" \t "<<distance[i]<<endl;
    }
}

void bellmanFord(vector<vector<int>> &graph, int n, int src) {
    // make vector of edges
    vector<Edge> edges;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(graph[i][j] != 0) {
                Edge edge;
                edge.u = i;
                edge.v = j;
                edge.wt = graph[i][j];
                edges.push_back(edge);
            }
        }
    }

    // initialize distance vector with INF
    vector<int> distance(n, INF);
    // distance of src from src is 0
    distance[src] = 0;

    // Repeat the relaxation for n-1 times
    for(int i=0; i<n-1; i++) {
        int cnt = 0;
        // Relaxation
        for(int j=0; j<edges.size(); j++) {
            Edge edge = edges[j];
            if(distance[edge.u] + edge.wt < distance[edge.v]) {
                distance[edge.v] = distance[edge.u] + edge.wt;
                cnt++;
            }
        }
        // if no edges get relaxed then break
        if(cnt==0) break;
    }

    // print ans
    printDistances(distance);
}

int main()
{
    // we have taken an undirected graph
    // algorithm works same on directed graph as well
    vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                  { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                  { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                  { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                  { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                  { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                  { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                  { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                  { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // function call
    bellmanFord(graph, 9, 0);

    return 0;
}
