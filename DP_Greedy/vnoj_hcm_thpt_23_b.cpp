// https://oj.vnoi.info/problem/hcm_thpt_23_b
#include <bits/stdc++.h>
using namespace std;

int n, k, dp[405][405], sum[405], mx[405][405], a[405];

int cost(int i, int j) {
    if(i > j) return 0;
    return mx[i][j] * (j - i + 1) - (sum[j] - sum[i - 1]);
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        mx[i][i] = a[i];
    }
    for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            mx[i][j] = max(mx[i + 1][j], mx[i][j - 1]);
        }
    }
    memset(dp, 10000, sizeof(dp));
    for(int i = 1; i <= n; i ++) dp[1][i] = cost(1, i);
    for(int g = 2; g <= k + 1; g ++) {
        for(int i = 2; i <= n; i ++) {
            dp[g][i] = dp[g - 1][i];
            for(int j = i - 1; j >= 1; j --) {
                dp[g][i] = min(dp[g][i], dp[g - 1][j] + cost(j + 1, i));
            } 
        }
    }
    int ans = 1e9;
    for(int i = 1; i <= k + 1; i ++) ans = min(ans, dp[i][n]);
    cout << ans;
}