// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, dp[5005][13], mod = 1e9 + 7, ans;

signed main() {
    cin >> n;
    for(int i = 1; i <= 12; i ++) dp[1][i] = 1;
    for(int i = 2; i <= n; i ++) {
        dp[i][1] = dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][6] + dp[i - 1][11];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][7] + dp[i - 1][9] + dp[i - 1][12];
        dp[i][3] = dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][7] + dp[i - 1][8];
        dp[i][4] = dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][8] + dp[i - 1][11];
        dp[i][5] = dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][9] + dp[i - 1][10];
        dp[i][6] = dp[i - 1][1] + dp[i - 1][7] + dp[i - 1][8] + dp[i - 1][10] + dp[i - 1][11];
        dp[i][7] = dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][6] + dp[i - 1][12];
        dp[i][8] = dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][12];
        dp[i][9] = dp[i - 1][2] + dp[i - 1][5] + dp[i - 1][10] + dp[i - 1][11];
        dp[i][10] = dp[i - 1][5] + dp[i - 1][6] + dp[i - 1][9] + dp[i - 1][12];
        dp[i][11] = dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][9] + dp[i - 1][12];
        dp[i][12] = dp[i - 1][2] + dp[i - 1][7] + dp[i - 1][8] + dp[i - 1][10] + dp[i - 1][11];
        for(int j = 1; j <= 12; j ++) dp[i][j] %= mod;
    }
    for(int i = 1; i <= 12; i ++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans;
}