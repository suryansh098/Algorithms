#include <iostream>
#include <vector>
using namespace std;

// Dynamic Programming: Problem 10 [Coin Change Permutation]
/*
    Given coins : 2, 3, 5, 6
    and tar : 7

    find num of permutations to pay target amt.
*/

int permutations(vector<int> &coins, int n, int amt) {
    vector<int> dp(amt+1, 0);
    dp[0] = 1;

    for(int i=1; i <= amt; i++) {
        for(int j=0; j<n; j++) {
            if(coins[j] <= i) {
                int remAmt = i-coins[j];
                dp[i] += dp[remAmt];
            }
        }
    }

    return dp[amt];
}

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for(int i=0; i<n; i++)
        cin >> coins[i];

    int tar;
    cin >> tar;

    cout << permutations(coins, n, tar);
    return 0;
}
