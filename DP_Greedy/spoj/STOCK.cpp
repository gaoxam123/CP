// https://oj.vnoi.info/problem/stock
#include <bits/stdc++.h>
using namespace std;

int m, s, d, a[55][15], dp[55], f[55][500005];

int main() {
    cin >> s >> d >> m;
    for(int i = 1; i <= s; i ++) {
        for(int j = 1; j <= d; j ++) {
            cin >> a[i][j];
        }
    }
    dp[1] = m;
    for(int j = 2; j <= d; j ++) {
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= s; i ++) {
            for(int k = 1; k <= dp[j - 1]; k ++) {
                if(a[i][j - 1] <= k) f[i][k] = max(f[i - 1][k], f[i][k - a[i][j - 1]] + a[i][j] - a[i][j - 1]);
                else f[i][k] = f[i - 1][k];
            }
        }
        dp[j] = dp[j - 1] + f[s][dp[j - 1]];
    }
    cout << dp[d];
}