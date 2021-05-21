#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// [DIJKSTRA] : Single Source Shortest Path Algorithm

// this function chooses the vertex with minimum distance
// from list of vertices that are not yet included in the path
int minDistance(vector<int> &dist, vector<bool> &inc, int n) {
    int min = INT_MAX, index;

    for(int i=0; i<n; i++) {
        if(inc[i] == false && dist[i] <= min)
            min = dist[i], index = i;
    }
    return index;
}

// this function prints the minimum distance of all vertices from src
void printDistances(vector<int> &distance) {
    cout<<"Vertex \t Distance from Source"<<endl;
    for(int i=0; i<distance.size(); i++) {
        cout<<i<<" \t "<<distance[i]<<endl;
    }
}

void dijkstraAlgorithm(vector<vector<int>> &graph, int src, int n) {
    // initialize distance vector with INF
    // it stores the minimum distance from src to i at index i
    vector<int> distance(n, INT_MAX);

    // initialize include vector
    // it stores whether the vertex is included in current path or not
    vector<bool> include(n, false);

    // distance of src from src is 0
    distance[src] = 0;

    // find shortest path of all vertices
    for(int i = 0; i < n-1; i++) {
        // find the closest vertex which is not included in current path
        int curr = minDistance(distance, include, n);

        // include that vertex in current path
        include[curr] = true;

        // Update distance of adjacent vertices
        for(int vertex=0; vertex < n; vertex++) {

            // if vertex is not included in the path and there is a edge from curr to vertex and
            // the distance of src till curr is not INF and finally the distance of src till curr +
            // the distance of vertex from curr is less than distance of vertex from src
            if(!include[vertex] && graph[curr][vertex] && distance[curr] != INT_MAX
                && distance[curr] + graph[curr][vertex] < distance[vertex])
                // then update
                distance[vertex] = distance[curr] + graph[curr][vertex];
        }
    }

    // print the outputs
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
    dijkstraAlgorithm(graph, 0, 9);

    return 0;
}
