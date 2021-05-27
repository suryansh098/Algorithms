#include <iostream>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

// Dynamic Programming: Problem 7 [Unbounded Knapsack]

// We are given with weights and their respective values.
// We are also given with max-weight.
// We need to pick weights such that the sum of values is max
// and sum of weights is less than max-weight.
// In this problem, we can pick same weight any number of times

int unboundedKnapsack(vector<int> &wts, vector<int> &vals, int n, int limit) {
    // initialize dp
    vector<vector<int>> dp(n+1, vector<int>(limit+1, 0));

    // iterate over all weights
    for(int i=1; i<=n; i++) {
        int wt = wts[i-1];
        int val = vals[i-1];

        // for given limit
        for(int j=1; j<=limit; j++) {
            // if curr limit is less than weight
            // then prev max is curr max
            if(j<wt)
                dp[i][j] = dp[i-1][j];
            // else curr max will be max of prev max
            // and curr val + max of curr limit - curr weight
            else
                dp[i][j] = max(dp[i-1][j], val + dp[i][j-wt]);
        }
    }

    // return ans
    return dp[n][limit];
}

int main() {
    // num of items
    int n;
    cin >> n;

    // input weights
    vector<int> wts(n);
    for(int i=0; i<n; i++)
        cin >> wts[i];

    // input values
    vector<int> vals(n);
    for(int i=0; i<n; i++)
        cin >> vals[i];

    // input max weight
    int limit;
    cin >> limit;

    // output max value
    cout << unboundedKnapsack(wts, vals, n, limit);
}
