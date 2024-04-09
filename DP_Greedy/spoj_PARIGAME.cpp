// https://oj.vnoi.info/problem/parigame
#include <bits/stdc++.h>
using namespace std;

int t, n, a[505][505], r[505][505], c[505][505];
int dp[505][505];

int main() {
    cin >> t;
    while(t --) {
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                cin >> a[i][j];
                a[i][j] %= 2;
            }
        }
        memset(dp, 0, sizeof(dp));
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));

        if(a[1][1] % 2 == 1) dp[1][1] = false;
        else dp[1][1] = true;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                r[i][j] = (r[i][j - 1] + a[i][j]) % 2;
                c[i][j] = (c[i - 1][j] + a[i][j]) % 2;
            }
        }
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                dp[i][j] = (!c[i][j] && !dp[i][j - 1]) | (!r[i][j] && !dp[i - 1][j]);
            }
        }
        if(dp[n][n] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}