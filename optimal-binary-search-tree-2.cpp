
#include <iostream>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

// Dynamic Programming: Problem 8 [Optimal Binary Search Tree (Successful & Unsuccessful Probability)]
/*
    Let successful search prob = p
    and unsuccessful search prob = q

    keys = { 10, 20, 30, 40 }
    p = { 0.1, 0.2, 0.1, 0.2 }
    q = { .1, .05, .15, .05, .05 }

    We have to find optimal BST such that the total cost of searching is minimum.

*/

void printArray(vector<vector<float>> &arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        for(int j=1; j<n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void printArray(vector<vector<int>> &arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        for(int j=1; j<n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

float optimalBST(vector<int> &keys, vector<float> &p, vector<float> &q, int n) {
    vector<vector<float>> W(n+1, vector<float>(n+1, 0));
    vector<vector<float>> C(n+1, vector<float>(n+1, 0));
    vector<vector<int>> root(n+1, vector<int>(n+1, 0));

    for(int i=0; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(j==i+1)
                W[i][j] = p[j-1] + q[j-1] + q[j];
            else
                W[i][j] = W[i][j-1] + p[j-1] + q[j];
        }
    }

    for(int s=0; s<=n; s++) {
        for(int i=0; i<=n-s; i++) {
            int j = i+s;

            if(i!=j) C[i][j] = INF;

            for(int k=i+1; k<=j; k++) {
                float temp = C[i][j];
                C[i][j] = min(C[i][j], C[i][k-1] + C[k][j] + W[i][j]);
                if(C[i][j] != temp)
                    root[i][j] = k;
            }
        }
    }

    cout << "\nMin Cost Array : " << endl;
    printArray(C);

    cout << "\nRoots of BSTs : " << endl;
    printArray(root);
    return C[0][n];
}

int main() {
    vector<int> keys = {10, 20, 30, 40};
    vector<float> p = { 0.1, 0.2, 0.1, 0.2 };
    vector<float> q = { 0.1, 0.05, 0.15, 0.05, 0.05 };

    float minCost = optimalBST(keys, p, q, keys.size());
    cout << "\nMin Cost : " << minCost;
}
