// https://leetcode.com/problems/paint-house-iii/description/
#include <bits/stdc++.h>
using namespace std;

int m, n, target, a[105], cost[105][25], dp[105][25][105], ans = 1e9;

int main() {
    cin >> m >> n >> target;
    for(int i = 1; i <= m; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> cost[i][j];
        }
    }
    // memset(dp, 0x3f, sizeof(dp));
    // dp[i][j][k] -> paint the i-th house with j color and currently have k neighborhoods
    // dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i][j], dp[i - 1][l != j][k - 1] + cost[i][l])
    for(int j = 1; j <= n; j ++) {
        dp[1][j][1] = cost[1][j];
        // dp[0][j][0] = 0;
    }
    for(int k = 1; k <= target; k ++) {
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(i < k) {
                    dp[i][j][k] = 1e9;
                    continue;
                }
                if(i == 1 && k == 1) {
                    dp[i][j][k] = cost[1][j];
                    continue;
                }
                dp[i][j][k] = 1e9;
                for(int l = 1; l <= n; l ++) {
                    if(j != l) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][l][k - 1] + cost[i][l]);
                    else dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i][j]);
                }
            }
        }
    }
    for(int j = 1; j <= n; j ++) {
        ans = min(ans, dp[n][j][target]);
    }
    if(ans < 1e9) cout << ans;
    else cout << "-1";
}