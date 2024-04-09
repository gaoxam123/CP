// https://oj.vnoi.info/problem/qbseq
#include <bits/stdc++.h>
using namespace std;

int n, k, a[1005], dp[1005][55];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j < k; j ++) {
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < k; j ++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - a[i]) % k >= 0 ? (j - a[i]) % k : (j - a[i]) % k + k] + 1);
        }
    }
    cout << dp[n][0];
}