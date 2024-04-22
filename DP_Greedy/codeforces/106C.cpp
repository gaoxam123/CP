// https://codeforces.com/problemset/problem/106/C
#include <bits/stdc++.h>
using namespace std;

int n, m, c0, d0, a[15], b[15], c[15], d[15], dp[1005][15];

int main() {
    cin >> n >> m >> c0 >> d0;
    for(int i = 1; i <= m; i ++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for(int i = 1; i <= n; i ++) {
        for(int k = 1; k <= i / c0; k ++) {
            int dough = c0 * k;
            int cost = d0 * k;
            if(dough <= i) dp[i][0] = dp[i - dough][0] + cost;
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            for(int k = 0; k <= i / c0; k ++) {
                int dough = c0 * k;
                int cost = d0 * k;
                if(dough <= i) dp[i][j] = max(dp[i][j], dp[i - dough][j - 1] + d0);
            }
            for(int k = 0; k <= a[j] / b[j]; k ++) {
                int dough = c[j] * k;
                int cost = d[j] * k;
                if(dough <= i) dp[i][j] = max(dp[i][j], dp[i - dough][j - 1] + cost);
            }
        }
    }
    cout << dp[n][m];
}