#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Dynamic Programming: Problem 1 [Nth Fibonacci]

int findNthFibonacci(int n) {
    if(n<=1)
        return n;

    vector<int> dp(n+1, -1);
    dp[0] = 0, dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-2] + dp[i-1];
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    int result = findNthFibonacci(n);
    cout << result;
}
