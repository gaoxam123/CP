// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, K, dp[55][105][55], mod = 1e9 + 7, ans;

signed main() {
    cin >> n >> m >> K;
    // dp[i][j][k] => process first i elements, max value of which is j and search cost k
    // when we consider the ith element, we choose to add it to the increasing subsequence or not
    // add: dp[i][j][k] += dp[i - 1][k - 1 <= l < j][k - 1]
    // not add: dp[i][j][k] = dp[i - 1][j][k] * j
    // base cases: 
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(i == 1) dp[i][j][1] = 1;
            else {
                dp[i][j][1] = dp[i - 1][j][1] * j;
                dp[i][j][1] %= mod;
            }
        }
    }
    for(int k = 2; k <= K; k ++) {
        for(int i = k; i <= n; i ++) {
            for(int j = k; j <= m; j ++) {
                dp[i][j][k] = dp[i - 1][j][k] * j;
                dp[i][j][k] %= mod;
                for(int l = k - 1; l < j; l ++) {
                    dp[i][j][k] += dp[i - 1][l][k - 1];
                    dp[i][j][k] %= mod;
                }
            }
        }
    }
    for(int i = 1; i <= m; i ++) {
        ans += dp[n][i][K];
        ans %= mod;
    }
    cout << ans;
}