// https://leetcode.com/problems/cherry-pickup-ii/description/
#include <bits/stdc++.h>
using namespace std;

int n, m, a[75][75], dp[75][75][75], ans;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            for(int k = 1; k <= m; k ++) {
                dp[i][j][k] = -1e9;
            }
        }
    }
    dp[1][1][m] = a[1][1] + a[1][m];
    for(int i = 2; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            for(int k = 1; k <= m; k ++) {
                if(j == 1 && k == 1) dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j][k + 1], dp[i - 1][j + 1][k], dp[i - 1][j + 1][k + 1]});
                else if(j == m && k == m) dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j][k - 1], dp[i - 1][j - 1][k], dp[i - 1][j - 1][k - 1]});
                else if(j == 1 && k == m) dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j + 1][k], dp[i - 1][j][k - 1], dp[i - 1][j + 1][k - 1]});
                else if(j == m && k == 1) dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j - 1][k], dp[i - 1][j][k + 1], dp[i - 1][j - 1][k + 1]});
                else if(j == 1) dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j][k - 1], dp[i - 1][j][k + 1], dp[i - 1][j + 1][k], dp[i - 1][j + 1][k - 1], dp[i - 1][j + 1][k + 1]});
                else if(j == m) dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j][k - 1], dp[i - 1][j][k + 1], dp[i - 1][j - 1][k], dp[i - 1][j - 1][k - 1], dp[i - 1][j - 1][k + 1]});
                else if(k == 1) dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j - 1][k], dp[i - 1][j + 1][k], dp[i - 1][j][k + 1], dp[i - 1][j - 1][k + 1], dp[i - 1][j + 1][k + 1]});
                else if(k == m) dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j - 1][k], dp[i - 1][j + 1][k], dp[i - 1][j][k - 1], dp[i - 1][j - 1][k - 1], dp[i - 1][j + 1][k - 1]});
                else {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i - 1][j - 1][k], dp[i - 1][j + 1][k], \
                    dp[i - 1][j][k - 1], dp[i - 1][j - 1][k - 1], dp[i - 1][j + 1][k - 1], \
                    dp[i - 1][j][k + 1], dp[i - 1][j - 1][k + 1], dp[i - 1][j + 1][k + 1]});
                }
                if(j == k) dp[i][j][k] += a[i][j];
                else dp[i][j][k] += a[i][j] + a[i][k];
            }
        }
    }
    for(int j = 1; j <= m; j ++) {
        for(int k = 1; k <= m; k ++) {
            ans = max(ans, dp[n][j][k]);
        }
    }
    cout << ans;
}