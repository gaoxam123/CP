// https://oj.vnoi.info/problem/zabava
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, a[105], dp[105][505], f[105][505];

int compute_f(int n, int k) {
    int p = n / k;
    int y = n % k;
    int x = k - y;
    return x * (p + 1) * p / 2 + y * (p + 1) * (p + 2) / 2;
}

signed main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[x] ++;
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = 0; j <= k; j ++) f[i][j] = compute_f(a[i], j + 1);
    }
    for(int j = 0; j <= k; j ++) {
        dp[1][j] = f[1][j];
    }
    for(int i = 2; i <= m; i ++) {
        for(int j = 0; j <= k; j ++) {
            dp[i][j] = dp[i - 1][j] + f[i][0];
            for(int c = 1; c <= j; c ++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - c] + f[i][c]);
            }
        }
    }
    cout << dp[m][k];
}