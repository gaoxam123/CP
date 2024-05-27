// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/
#include <bits/stdc++.h>
using namespace std;

int n, dp[1005][2005], k, sum[1005][2005], coins_in_pile[1005];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> coins_in_pile[i];
        for(int j = 1; j <= coins_in_pile[i]; j ++) {
            int x;
            cin >> x;
            sum[i][j] = sum[i][j - 1] + x;
        }
    }
    for(int j = 1; j <= k; j ++) {
        for(int i = 1; i <= n; i ++) {
            for(int l = 0; l <= min(j, coins_in_pile[i]); l ++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - l] + sum[i][l]);
            }
        }
    }
    cout << dp[n][k];
}