// https://oj.vnoi.info/problem/qbpal
#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
int dp[123][123];

signed main() {
    cin >> s;
    int n = s.size();
    s = " " + s;
    for(int i = 1; i <= n; i ++) {
        dp[i][i] = 1;
    }
    for(int k = 1; k <= n; k ++) {
        for(int i = 1; i <= n - k; i ++) {
            int j = i + k;
            if(s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            }
            else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    cout << dp[1][n];
}