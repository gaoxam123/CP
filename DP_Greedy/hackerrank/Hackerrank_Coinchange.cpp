// https://www.hackerrank.com/challenges/coin-change/problem
#include <bits/stdc++.h>
using namespace std;

int n, m, a[55], dp[55][255];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i ++) {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(a[i] <= j) {
                dp[i][j] = dp[i][j - a[i]] + dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][n];
}