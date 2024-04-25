// https://codeforces.com/problemset/problem/38/E
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, dp[3005][3005], cost[3005][3005], ans = 1e18;
pair <int, int> a[3005];

void solve(int i, int l, int r, int optL, int optR) {
    if(l > r) return;
    int mid = (l + r) / 2;
    int pos = 0;
    for(int j = optL; j <= min(optR, mid); j ++) {
        if(dp[i][mid] > dp[i - 1][j - 1] + cost[j][mid]) {
            pos = j;
            dp[i][mid] = dp[i - 1][j - 1] + cost[j][mid];
        }
    }
    solve(i, l, mid - 1, optL, pos);
    solve(i, mid + 1, r, pos, optR);
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        cost[i][i] = a[i].second;
        for(int j = i + 1; j <= n; j ++) {
            cost[i][j] = cost[i][j - 1] + a[j].first - a[i].first;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i ++) {
        dp[1][i] = cost[1][i];
        if(i > 1) dp[i][i] = dp[i - 1][i - 1] + a[i].second;
    }
    for(int g = 2; g < n; g ++) {
        // for(int i = g + 1; i <= n; i ++) {
        //     for(int j = i; j >= g; j --) {
        //         dp[g][i] = min(dp[g][i], dp[g - 1][j - 1] + cost[j][i]);
        //     }
        // }
        solve(g, 1, n, 1, n);
    }
    for(int g = 1; g <= n; g ++) {
        ans = min(ans, dp[g][n]);
    }
    cout << ans;
}