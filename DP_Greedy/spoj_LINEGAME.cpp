// https://oj.vnoi.info/problem/linegame
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[1000005], dp[1000005][2][2];

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        dp[i][1][0] = max(dp[i - 1][1][1], dp[i - 1][0][1]) - a[i];
        dp[i][1][1] = max(dp[i - 1][1][0], dp[i - 1][0][0]) + a[i];
        dp[i][0][1] = max(dp[i - 1][1][1], dp[i - 1][0][1]);
        dp[i][0][0] = max(dp[i - 1][1][0], dp[i - 1][0][0]);
    }
    cout << max(dp[n][1][1], max(dp[n][1][0], max(dp[n][0][1], dp[n][0][0])));
}