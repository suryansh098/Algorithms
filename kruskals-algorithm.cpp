#include <iostream>
#include <vector>
#include <queue>
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

// class denoting an edge
class Edge {
    public:
    int u;
    int v;
    int wt;

    // constructor
    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

// compator class
class compare {
    public:
    bool operator()(Edge* a, Edge* b)  {
        return (a->wt > b->wt);
    }
};

// utility function
int printMST(vector<Edge*> &MST) {
    // initialize min cost
    int minCost = 0;

    // iterate over all edges
    cout<<" Edge \t\t Weight"<<endl;
    for(int i=0; i<MST.size(); i++) {
        auto x = MST[i];
        cout<<x->u<<" -- "<<x->v<<"\t\t "<<x->wt<<endl;
        minCost += x->wt;
    }

    // return min cost
    return minCost;
}

int kruskalsAlgo(vector<vector<int>> &graph, int V) {

    // initialize pq, visit vector, MST
    priority_queue<Edge*, vector<Edge*>, compare> pq;
    vector<bool> vis(V, false);
    vector<Edge*> MST;

    // add all the edges to pq
    for(int i=0; i<graph.size(); i++) {
        for(int j=i; j<graph[0].size(); j++) {
            // check if there's an edge b/w i & j
            if(graph[i][j] != 0) {
                // initialize edge
                Edge* e = new Edge(i, j, graph[i][j]);
                pq.push(e);
            }
        }
    }

    // we need V-1 edges for MST
    for(int i=0; i<V-1; i++) {
        // take the minimum edge
        Edge* e = pq.top();
        pq.pop();

        // check if including it does not form a cycle
        // i.e. both vertices should not be already visited
        if(!(vis[e->u] && vis[e->v])) {
            // mark them as visited
            vis[e->u] = vis[e->v] = true;
            // push it in MST
            MST.push_back(e);
        }
        else {
            // free memory of unused edge
            delete e;
        }
    }

    // print MST and return min cost
    return printMST(MST);
}

int main() {
    vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                                  { 2, 0, 3, 8, 5 },
                                  { 0, 3, 0, 0, 7 },
                                  { 6, 8, 0, 0, 9 },
                                  { 0, 5, 7, 9, 0 } };

    int minCost = kruskalsAlgo(graph, graph.size());
    cout<<"\nMinimum Cost of MST : "<<minCost;
}
