// https://codeforces.com/problemset/problem/148/E
#include <bits/stdc++.h>
using namespace std;

int n, m, dp[105][10005], a[105][105], sum[105][105], best[105][105], sz[105];
// n -> 100, m -> 10000, l -> 100

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j ++) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
        for(int j = 1; j <= k; j ++) {
            for(int l = 0; l <= j; l ++) {
                best[i][j] = max(best[i][j], sum[i][l] + sum[i][k] - sum[i][k - (j - l)]);
            }
        }
        sz[i] = k;
    }
    for(int j = 1; j <= m; j ++) {
        for(int i = 1; i <= n; i ++) {
            int k = sz[i];
            for(int l = 0; l <= min(k, j); l ++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + best[i][l]);
            }
        }
    }
    cout << dp[n][m];
}