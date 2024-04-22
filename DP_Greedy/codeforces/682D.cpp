// https://codeforces.com/contest/682/problem/D
#include <bits/stdc++.h>
using namespace std;

int n, m, k, dp[1005][1005][15];
string a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    for(int p = 1; p <= k; p ++) {
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(a[i] == b[j]) dp[i][j][p] = max(dp[i - 1][j - 1][p - 1], dp[i - 1][j - 1][p]) + 1;
            }
        }
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                dp[i][j][p] = max(dp[i][j][p], max(dp[i - 1][j][p], dp[i][j - 1][p]));
            }
        }
    }
    cout << dp[n][m][k];
}