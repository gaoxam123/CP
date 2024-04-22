// https://oj.vnoi.info/problem/mpilot
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[10005], b[10005], dp[2][10005];

// main idea: dp[i][j] is the min cost considering first i pilots and there are still j assistants not having a main pilot

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
    }
    dp[1][1] = b[1];
    for(int i = 2; i <= n; i ++) {
        int m = min(i, n / 2);
        int id = i % 2;
        dp[id][0] = dp[1 - id][1] + a[i];
        dp[id][m] = dp[1 - id][m - 1] + b[i];
        for(int j = 1; j < m; j ++) {
            dp[id][j] = min(dp[1 - id][j - 1] + b[i], dp[1 - id][j + 1] + a[i]);
        }
    }
    cout << dp[0][0];
}