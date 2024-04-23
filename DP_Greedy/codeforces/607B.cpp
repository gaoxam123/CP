// https://codeforces.com/problemset/problem/607/B
#include <bits/stdc++.h>
using namespace std;

int n, a[505], dp[505][505], f[505][505], p[505][505];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        dp[i][i] = 1;
        f[i][i] = 1;
        p[i][i] = 1;
        for(int j = i + 1; j <= n; j ++) {
            p[i][j] = j - i + 1;
        }
    }
    for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            if(a[i] == a[j] && i + 1 == j) f[i][j] = 1;
            else if(a[i] == a[j] && f[i + 1][j - 1] == 1) f[i][j] = dp[i][j] = 1;
        }
    }
    for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            for(int k = j - 1; k >= i; k --) {
                if(f[k][j]) p[i][j] = min(p[i][j], p[i][k - 1] + 1);
            }
        }
    }
    /*for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            if(i + 1 == j) {
                if(a[i] == a[j]) dp[i][j] = 1;
                else dp[i][j] = 2;
            }
            else {
                if(a[i] == a[j]) dp[i][j] = min({dp[i][j], p[i][j], dp[i + 1][j - 1]});
                else dp[i][j] = min({dp[i][j], dp[i + 1][j] + 1, dp[i][j - 1] + 1, p[i][j]});
            }
        }
    }*/
    for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            if(i + 1 == j) {
                if(a[i] == a[j]) dp[i][j] = 1;
                else dp[i][j] = 2;
            }
            else {
                if(a[i] == a[j]) dp[i][j] = dp[i + 1][j - 1];
                for(int k = i; k < j; k ++) {
                    dp[i][j] = min({dp[i][j], dp[i][k] + dp[k + 1][j]});
                }
            }
        }
    }
    cout << dp[1][n];
}