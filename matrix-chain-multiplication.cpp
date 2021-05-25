#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Dynamic Programming: Problem 4 [Matrix Chain Multiplication]
// We need to find the minimum cost of multiplication of n-matrices.
/*
    For Example: Given 4 matrices A1(5, 4), A2(4, 6), A3(6, 2), A4(2, 7)
    We can multiply them in any order, but we don't have to multiply them.
    We just need to find the minimum cost and the order of multiplication
    from all possible orders of multiplication.
*/
void printBreakPoints(vector<vector<int>> &s) {
    cout << "Break Points:" << endl;
    // for ex: s[1][3] = 2 => (1*2) *  3
    // i.e. for matrix 1, 2, 3
    // take 2 from starting first then take 3
    for(int i=1; i<s.size(); i++) {
        for(int j=1; j<s.size(); j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
}

int matrixChain(vector<int> &p, int n) {
    // matrix m will store the minimum cost of multiplying
    // the matrix from i to j at position i,j
    vector<vector<int>> m(n, vector<int>(n, 0));

    // matrix s will store the break points
    vector<vector<int>> s(n, vector<int>(n, 0));

    int temp, j, mini;

    // iterate on dimensions
    for(int d=1; d<n-1; d++) {
        for(int i=1; i<n-d; i++) {
            j=i+d;
            mini = INT_MAX;
            for(int k=i; k<=j-1; k++) {
                // applying the formula for min cost
                temp = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if(mini > temp) {
                    mini = temp;
                    s[i][j] = k;
                }
            }
            m[i][j] = mini;
        }
    }

    // print break points
    printBreakPoints(s);

    return m[1][n-1];
}

int main() {
    // number of dimesions
    // for n matrix multiplication
    // n matrix should have n+1 dimesions
    int n;
    cin >> n;

    // dimension values
    vector<int> p(n);
    for(int i=0; i<n; i++)
        cin >> p[i];

    int result = matrixChain(p, n);
    cout << "Min cost : " << result;
}
