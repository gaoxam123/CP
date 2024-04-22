// https://codeforces.com/contest/1625/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, l, k, d[505], a[505], dp[505][505], ans = 1e18;

signed main() {
    cin >> n >> l >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> d[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    n ++;
    d[n] = l;
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for(int i = 2; i <= n; i ++) {
        for(int j = 0; j <= min(k, i - 1); j ++) {
            for(int g = 1; g < i; g ++) {
                if(g - 1 > j) break;
                dp[i][j] = min(dp[i][j], dp[i - g][j - g + 1] + (d[i] - d[i - g]) * a[i - g]);
            }
        }
    }
    for(int i = 0; i <= k; i ++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans;
}