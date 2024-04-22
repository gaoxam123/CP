// https://oj.vnoi.info/problem/bedao_r08_negiko
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, K, a[1005], b[1005], dp[1005][1005][23], mod = 1e9 + 9;

signed main() {
    cin >> n >> m >> K;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i ++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i] > b[j]) dp[i][j][1] = j + dp[i - 1][j][1];
            else dp[i][j][1] = dp[i][j - 1][1];
        }
    }   
    for(int k = 2; k <= K; k ++) {
        for(int i = k; i <= n; i ++) {
            for(int j = k; j <= m; j ++) {
                if(a[i] <= b[j]) {
                    dp[i][j][k] = dp[i][j - 1][k] % mod + dp[i - 1][j][k] % mod;
                    dp[i][j][k] %= mod;
                }
                else {
                    dp[i][j][k] = dp[i - 1][j][k] % mod + dp[i][j - 1][k] % mod + dp[i - 1][j - 1][k - 1] % mod;
                    dp[i][j][k] %= mod;
                }
                dp[i][j][k] -= dp[i - 1][j - 1][k] % mod;
                dp[i][j][k] %= mod;
            }
        }
    }
    cout << dp[n][m][K];
}