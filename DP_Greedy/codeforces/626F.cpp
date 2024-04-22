// https://codeforces.com/problemset/problem/626/F
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, K, a[205], dp[2][205][1005], mod = 1e9 + 7, ans;

signed main() {
    cin >> n >> K;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dp[0][0][0] = 1;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= n; j ++) {
            for(int k = 0; k <= K; k ++) {
                if(!dp[0][j][k]) continue;
                if(k + j * (a[i] - a[i - 1]) <= K) {
                    int cost = k + j * (a[i] - a[i - 1]);
                    dp[1][j][cost] += dp[0][j][k] * (j + 1);
                    dp[1][j][cost] %= mod;
                    if(j > 0) {
                        dp[1][j - 1][cost] += dp[0][j][k] * j;
                        dp[1][j - 1][cost] %= mod;
                    }
                    if(j < n) {
                        dp[1][j + 1][cost] += dp[0][j][k];
                        dp[1][j + 1][cost] %= mod;
                    }
                }
            }
        }
        for(int j = 0; j <= n; j ++) {
            for(int k = 0; k <= K; k ++) {
                dp[0][j][k] = dp[1][j][k];
                dp[1][j][k] = 0;
            }
        }
    }
    for(int k = 0; k <= K; k ++) {
        ans += dp[0][0][k];
        ans %= mod;
    }
    cout << ans;
}