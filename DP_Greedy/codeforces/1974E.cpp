// https://codeforces.com/problemset/problem/1974/E
#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, m, x;
int c[55], h[55], dp[55][100005], prefix[55];

signed main() {
    cin >> t;
    while(t --) {
        int sum = 0;
        memset(prefix, 0, sizeof(prefix));
        cin >> m >> x;
        for(int i = 1; i <= m; i ++) {
            cin >> c[i] >> h[i];
            sum += h[i];
            prefix[i] = prefix[i - 1] + h[i];
        }
        // original dp: max happiness considering first i days and current budget is j
        // int ans = 0;
        // memset(dp, 0, sizeof(dp));
        // for(int i = 1; i <= m; i ++) {
        //     for(int j = 0; j <= x * (i - 1); j ++) {
        //         if(j < c[i]) dp[i][j] = dp[i - 1][j];
        //         else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + h[i]);
        //         if(i == m) ans = max(ans, dp[i][j]);
        //     }
        // }
        // cout << ans << endl;
        // dp[i][j]: min cost to get j happiness in j days
        for(int i = 0; i <= m; i ++) {
            for(int j = 1; j <= sum; j ++) {
                dp[i][j] = 1e18;
            }
        }
        // dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - h[i]] + c[i])
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= prefix[i]; j ++) {
                if(j >= h[i]) {
                	dp[i][j] = dp[i - 1][j];
                	if(dp[i - 1][j - h[i]] + c[i] <= x * (i - 1)) dp[i][j] = min(dp[i][j], dp[i - 1][j - h[i]] + c[i]);
                }
                else dp[i][j] = dp[i - 1][j];
            }
        }
        for(int j = sum; j >= 0; j --) {
            if(dp[m][j] < 1e18) {
                cout << j << endl;
                break;
            }
        }
    }
}