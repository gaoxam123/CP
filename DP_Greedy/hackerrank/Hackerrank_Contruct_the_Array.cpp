// https://www.hackerrank.com/challenges/construct-the-array/problem
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, x, mod = 1e9 + 7, dp[100005][2];

signed main() {
    cin >> n >> k >> x;
    if(1 == x) dp[1][1] = 1;
    else dp[1][0] = 1;
    for(int i = 2; i < n; i ++) {
        dp[i][0] = dp[i - 1][0] * (k - 2) + dp[i - 1][1] * (k - 1);
        dp[i][0] %= mod;
        dp[i][1] = dp[i - 1][0];
        dp[i][1] %= mod;
    }
    dp[n][1] = dp[n - 1][0];
    cout << dp[n][1];
}