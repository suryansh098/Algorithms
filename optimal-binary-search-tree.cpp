#include <iostream>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

// Dynamic Programming: Problem 8 [Optimal Binary Search Tree (Successful Search Only)]
/*

    Let keys = { 10, 20, 30 }
    and freq = { 3, 2, 5 }

    Possible binary search trees :

    10        |  10      |      20     |    30     |        30
      \       |    \     |     /  \    |   /       |       /
       20     |     30   |   10    30  | 10        |     20
         \    |    /     |             |   \       |    /
          30  |  20      |             |    20     |  10
    cost=18     cost=19     cost=18       cost=17       cost=18

    Optimal binary search tree = (4)
    Min Cost = 17

*/

void printArray(vector<vector<int>> &arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        for(int j=1; j<n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int optimalBST(vector<int> &keys, vector<int> &freq, int n) {
    vector<vector<int>> W(n+1, vector<int>(n+1, 0));
    vector<vector<int>> C(n+1, vector<int>(n+1, 0));
    vector<vector<int>> root(n+1, vector<int>(n+1, 0));

    for(int i=0; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            if(j==i+1)
                W[i][j] = freq[j-1];
            else
                W[i][j] = W[i][j-1] + freq[j-1];
        }
    }

    for(int s=0; s<=n; s++) {
        for(int i=0; i<=n-s; i++) {
            int j = i+s;

            if(i!=j) C[i][j] = INF;

            for(int k=i+1; k<=j; k++) {
                int temp = C[i][j];
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
    vector<int> freq = {4, 2, 6, 3};

    int minCost = optimalBST(keys, freq, keys.size());
    cout << "\nMin Cost : " << minCost;
}
