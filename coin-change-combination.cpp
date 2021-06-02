#include <iostream>
#include <vector>
using namespace std;

// Dynamic Programming: Problem 10 [Coin Change Permutation]
/*
    Given coins : 2, 3, 5, 6
    and tar : 7

    find num of combinations to pay target amt.
*/

int combinations(vector<int> &coins, int n, int amt) {
    vector<int> dp(amt+1, 0);
    dp[0] = 1;


    for(int i=0; i<n; i++) {
        for(int j=coins[i]; j <= amt; j++) {
            dp[j] += dp[j - coins[i]];
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

    cout << combinations(coins, n, tar);
    return 0;
}
