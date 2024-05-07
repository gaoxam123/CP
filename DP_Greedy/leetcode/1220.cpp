// https://leetcode.com/problems/count-vowels-permutation/description/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, dp[20005][6], ans, mod = 1e9 + 7;

signed main() {
    cin >> n;
    dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = 1;
    for(int i = 2; i <= n; i ++) {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][3];
        dp[i][3] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5];
        dp[i][4] = dp[i - 1][3] + dp[i - 1][5];
        dp[i][5] = dp[i - 1][1];
        for(int j = 1; j <= 5; j ++) dp[i][j] %= mod;
    }
    for(int i = 1; i <= 5; i ++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans;
}