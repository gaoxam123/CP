// https://codeforces.com/contest/1675/problem/G
#include <bits/stdc++.h>
using namespace std;

int n, m, a[255], dp[255][255][255], sum[255], ans = 1e9;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    // dp[i][curr_sum][last] => first i elements, total sum and last one
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i <= m; i ++) dp[1][i][i] = abs(a[1] - i);
    for(int i = 2; i <= n; i ++) {
        for(int k = 0; k <= m; k ++) {
            for(int l = k; l <= m; l ++) {
                for(int j = l; j <= m - k; j ++) {
                    dp[i][j + k][k] = min(dp[i][j + k][k], dp[i - 1][j][l] + abs(j + k - sum[i]));
                }
            }
        }
    }
    for(int i = 0; i <= m; i ++) ans = min(ans, dp[n][m][i]);
    cout << ans;
}