// https://codeforces.com/problemset/problem/1132/F
#include <bits/stdc++.h>
using namespace std;

int n, dp[505][505];
string s;

int main() {
    cin >> n;
    cin >> s;
    s = " " + s;
    // memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i ++) {
        dp[i][i] = 1;
    }
    for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            if(i + 1 == j) {
                if(s[i] != s[j]) dp[i][j] = 2;
                else dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i + 1][j] + 1;
                // dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                for(int k = i + 1; k <= j; k ++) {
                    if(s[k] == s[i]) dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                    // if(s[k] == s[i]) dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
                }
            }
        }
    }
    cout << dp[1][n];
}