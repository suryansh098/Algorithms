#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Dynamic Programming: Problem 2 [Multigraph]
// Shortest Path from source to destination

#define INF INT_MAX

int shortestPath(vector<vector<int>> &graph, int n) {
    // initialize dp array
    // it stores shortest path from index i to dest
    vector<int> dp(n, INF);

    // distance from dest to dest is 0
    dp[n-1] = 0;

    // iterate over all other vertices
    for(int i=n-2; i>=0; i--) {
        // find min distance from that vertex to dest
        // and store it in dp at index vertex
        for(int j=i+1; j<n; j++) {
            // check if edge exists
            if(graph[i][j] != INF) {
                // find min distance
                dp[i] = min(dp[i], graph[i][j] + dp[j]);
            }
        }
    }

    // return the distance from src i.e. 0
    return dp[0];
}

int main()
{
    // Graph in the form of an adjacency matrix
    vector<vector<int>> graph =
      {{0, 1, 2, 5, INF, INF, INF, INF},
       {INF, 0, INF, INF, 4, 11, INF, INF},
       {INF, INF, 0, INF, 9, 5, 16, INF},
       {INF, INF, INF, 0, INF, INF, 2, INF},
       {INF, INF, INF, INF, 0, INF, INF, 18},
       {INF, INF, INF, INF, INF, 0, INF, 13},
       {INF, INF, INF, INF, INF, INF, 0, 2},
      {INF, INF, INF, INF, INF, INF, INF, 0}};

    cout << shortestPath(graph, graph.size());
    return 0;
}
