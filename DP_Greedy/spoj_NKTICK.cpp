// https://oj.vnoi.info/problem/nktick
#include <bits/stdc++.h>
using namespace std;

int n, t[60005], r[60005], dp[60005][2];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> t[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> r[i];
    }
    dp[1][0] = t[1];
    dp[1][1] = 1e9;
    for(int i = 2; i <= n; i ++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + t[i];
        dp[i][1] = dp[i - 1][0] - t[i - 1] + r[i - 1];
    }
    cout << min(dp[n][0], dp[n][1]);
}