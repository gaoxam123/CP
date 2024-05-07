// https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/
#include <bits/stdc++.h>
using namespace std;

int n, m, a[505], b[505], dp[505][505];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i ++) {
        cin >> b[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[1][1] = a[1] * b[1];
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            dp[i][j] = max({a[i] * b[j], dp[i - 1][j - 1] + a[i] * b[j], dp[i][j - 1], dp[i - 1][j]});
        }
    }
    cout << dp[n][m];
}