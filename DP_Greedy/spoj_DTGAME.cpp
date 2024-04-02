// https://oj.vnoi.info/problem/dtgame
#include <bits/stdc++.h>
using namespace std;

int n, a[2005], sum[2005], dp[2005][2005], f[2005][2005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = i;
    }
    for(int j = 2; j <= n; j ++) {
        for(int i = j - 1; i >= 1; i --) {
            for(int k = f[i][j - 1]; k <= f[i + 1][j]; k ++) {
                if(dp[i][j] < min(dp[i][k - 1] + sum[k - 1] - sum[i - 1], dp[k][j] + sum[j] - sum[k - 1])) {
                    dp[i][j] = min(dp[i][k - 1] + sum[k - 1] - sum[i - 1], dp[k][j] + sum[j] - sum[k - 1]);
                    f[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n];
}
