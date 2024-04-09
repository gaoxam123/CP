// https://oj.vnoi.info/problem/optcut
#include <bits/stdc++.h>
using namespace std;

int n, a[2005], dp[2005][2005], f[2005][2005], sum[2005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = i;
    }
    for(int j = 2; j <= n; j ++) {
        for(int i = j - 1; i >= 1; i --) {
            dp[i][j] = 1e9;
            for(int k = f[i][j - 1]; k <= f[i + 1][j]; k ++) {
                if(dp[i][j] > dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
                    f[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n];
}