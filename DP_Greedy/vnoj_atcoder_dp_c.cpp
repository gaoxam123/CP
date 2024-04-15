// https://oj.vnoi.info/problem/atcoder_dp_c
#include <bits/stdc++.h>
using namespace std;

int n, a[100005], b[100005], c[100005], dp[100005][3];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    dp[1][2] = c[1];
    for(int i = 2; i <= n; i ++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}