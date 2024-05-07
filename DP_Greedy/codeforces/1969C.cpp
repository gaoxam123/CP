// https://codeforces.com/problemset/problem/1969/C
#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, k, a[300005], dp[300005][15], sum[300005];

signed main() {
    cin >> t;
    while(t --) {
        cin >> n >> k;
        for(int i = 0; i <= n; i ++) {
            sum[i] = 0;
            for(int j = 0; j <= k; j ++) {
                dp[i][j] = 0;
                dp[0][j] = 0;   
            }
        }
        int mn = 1e18;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i ++) {
            dp[i][0] = dp[i - 1][0] + a[i];
            for(int j = 1; j <= k; j ++) {
                dp[i][j] = dp[i - 1][j] + a[i];
                for(int l = i - 1; l >= max((int)1, i - j); l --) {
                    dp[i][j] = min({dp[i][j], dp[l][j - (i - l)] + a[l] * (i - l), dp[l - 1][j - (i - l)] + a[i] * (i - l + 1)});
                }
            }
        }
        int ans = 1e18;
        for(int i = 0; i <= k; i ++) {
            ans = min(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
}