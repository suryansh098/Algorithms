#include <iostream>
#include <vector>
using namespace std;

// Dynamic Programming: Problem 9 [Longest Common Subsequence]
/*
    Given two strings:
    s1 = abcdef
    s2 = dbe

    LCS = be/de => 2

*/

int LCS(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int main() {

    string a;
    string b;
    cin >> a;
    cin >> b;

    cout << LCS(a, b);
    return 0;
}
