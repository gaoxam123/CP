// https://codeforces.com/problemset/problem/590/D
#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, dp[155][155 * 155];

int main() {
    cin >> n >> m >> k;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i <= n * n; i ++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i ++) {
        cin >> x;
        for(int j = min(i, m); j >= 1; j --) {
            for(int l = i - j; l <= min(k, n * n); l ++) {
                dp[j][l] = min(dp[j][l], dp[j - 1][l - i + j] + x);
            }
        }
    }
    cout << dp[m][min(k, n * n)];
}