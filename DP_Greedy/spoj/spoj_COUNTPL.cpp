// https://oj.vnoi.info/problem/countpl
#include <bits/stdc++.h>
using namespace std;

string s;
int dp[300], f[300][300];

int main() {
    cin >> s;
    s = " " + s;
    int n = s.size() - 1;
    for(int i = 1; i <= n; i ++) {
        f[i][i] = 1;
    }
    for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            if(s[i] == s[j]) {
                if(i + 1 == j) f[i][j] = 1;
                else if(f[i + 1][j - 1] == 1) f[i][j] = 1;
            }
        }
    }
    dp[1] = 1;
    for(int i = 2; i <= n; i ++) {
        dp[i] = i;
        for(int j = 1; j <= i; j ++) {
            if(f[j][i] == 1) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[n];
}