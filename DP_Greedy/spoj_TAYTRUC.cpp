// https://vn.spoj.com/problems/TAYTRUC/
#include <bits/stdc++.h>
using namespace std;

int n, m, a[10005], dp[10005][505][3];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    // 0: skip
    // 1: take one
    // 2: leave one
    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= 0; j --) {
            dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i - 1][j][2], dp[i - 1][j][1]));
            if(j < m)  dp[i][j][2] = max(dp[i - 1][j + 1][0], max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]));
            if(j == 1)  dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]) + a[i];
            else if(j > 1)  dp[i][j][1] = dp[i - 1][j - 1][1] + a[i];
        }
    }
    cout << max(dp[n][0][2], dp[n][0][0]);
}