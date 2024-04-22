// https://oj.vnoi.info/problem/mmaxper
#include <bits/stdc++.h>
using namespace std;

int n, a[1005], b[1005], dp[1005][2];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
    }
    dp[1][0] = b[1];
    dp[1][1] = a[1];
    for(int i = 2; i <= n; i ++) {
        dp[i][0] = max(dp[i - 1][0] + abs(a[i] - a[i - 1]), dp[i - 1][1] + abs(a[i] - b[i - 1])) + b[i];
        dp[i][1] = max(dp[i - 1][0] + abs(b[i] - a[i - 1]), dp[i - 1][1] + abs(b[i] - b[i - 1])) + a[i];
    }
    cout << max(dp[3][1], dp[3][0]);
}