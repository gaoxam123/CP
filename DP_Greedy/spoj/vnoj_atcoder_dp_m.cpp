// https://oj.vnoi.info/problem/atcoder_dp_m
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, a[105], dp[105][100005], sum[105], mod = 1e9 + 7, f[100005];

signed main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        dp[i][0] = 1;
        dp[i][1] = i;
        // f[i][0] = 1;
        // f[i][1] = i;
    }
    for(int i = 1; i <= n; i ++) {
        f[0] = dp[i][0];
        f[1] = dp[i][1];
        for(int j = 2; j <= min(sum[i], k); j ++) {
            // f[i][j] = f[i][j - 1] +  dp[i - 1][j]; 
            f[j] = f[j - 1] + dp[i - 1][j];
            // f[j] %= mod;
        }
        for(int j = 2; j <= min(sum[i], k); j ++) {
            // dp[i][j] = dp[i - 1][j];
            // dp[i][j] %= mod;
            // for(int l = j - 1; l >= max((int)0, j - a[i]); l --) {
            //     dp[i][j] += dp[i - 1][l];
            //     dp[i][j] %= mod;
            // }
            if(j - a[i] <= 0) {
                dp[i][j] = f[j];
                dp[i][j] %= mod;
            }
            else {
                dp[i][j] = f[j] - f[j - a[i] - 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][k];
}