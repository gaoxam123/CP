// https://oj.vnoi.info/problem/dtdoi
#include <bits/stdc++.h>
using namespace std;
#define int long long

int s, n, a[105], dp[105][10100], cnt;

signed main() {
    cin >> n >> s;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n + 1);
    if(s >= 20000) {
        cnt = (s - 20000) / a[n];
        s -= cnt * a[n];
    }
    for(int i = 1; i <= s; i ++) dp[0][i] = 1e9;
    for(int j = 1; j <= s; j ++) {
        for(int i = 1; i <= n; i ++) {
            if(a[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - a[i]] + 1);
        }
    }
    cout << dp[n][s] + cnt;
}