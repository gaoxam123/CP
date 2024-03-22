//https://vnspoj.github.io/problems/ZABAVA.html
#include <bits/stdc++.h>
using namespace std;

int n, a[505], dp[505][505], f[505][505], m, k;
int solve(int n, int k) {
    int p = n / k;
    int y = n - p * k;
    int x = k - y;
    return x * p * (p + 1) / 2 + y * (p + 1) * (p + 2) / 2;
}

int main() {
	ios_base::sync_with_stdio();
    cout.tie(0); cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) {
        int t;
        cin >> t;
        a[t] ++;
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = 0; j <= k; j ++) {
            f[i][j] = solve(a[i], j + 1);
        }
    }
    for(int j = 0; j <= k; j ++) dp[1][j] = f[1][j];

    for(int i = 2; i <= m; i ++) {
        for(int j = 0; j <= k; j ++) {
            dp[i][j] = dp[i - 1][j] + f[i][0];
            for(int c = 1; c <= j; c ++) {
                dp[i][j] = dp[i - 1][j - c] + f[i][c];
            }
        }
    }
    cout << dp[m][k];
}