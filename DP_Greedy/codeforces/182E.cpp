// https://codeforces.com/problemset/problem/182/E
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, l, a[105], b[105], dp[105][2][3005], mod = 1e9 + 7, ans, mn = 1e9;

signed main() {
    cin >> n >> l;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
        mn = min({mn, a[i], b[i]});
    }
    // dp[i][j][k] => current type i, rotation j, length k
    // dp[i][j][k] += dp[i - 1][j != i && a, b[j] == a, b[i]][k - a[i] || k - b[i]]
    for(int i = 1; i <= n; i ++) {
        dp[i][0][a[i]] = 1;
        dp[i][1][b[i]] = 1;
    }
    for(int k = mn + 1; k <= l; k ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(i != j && a[i] == a[j] && a[i] <= k) {
                    dp[i][0][k] += dp[j][1][k - a[i]];
                    dp[i][0][k] %= mod;
                }
                if(i != j && a[i] == b[j] && b[j] != a[j] && a[i] <= k) {
                    dp[i][0][k] += dp[j][0][k - a[i]];
                    dp[i][0][k] %= mod;
                }
                if(a[i] == b[i]) dp[i][1][k] = dp[i][0][k];
                else {
                    if(i != j && b[i] == a[j] && b[i] <= k) {
                        dp[i][1][k] += dp[j][1][k - b[i]];
                        dp[i][1][k] %= mod;
                    }
                    if(i != j && b[i] == b[j] && b[j] != a[j] && b[i] <= k) {
                        dp[i][1][k] += dp[j][0][k - b[i]];
                        dp[i][1][k] %= mod;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++) {
        ans += dp[i][0][l];
        ans %= mod;
        if(a[i] != b[i]) {
            ans += dp[i][1][l];
            ans %= mod;
        }
    }
    cout << ans;
}