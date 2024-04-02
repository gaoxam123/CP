// https://oj.vnoi.info/problem/atcoder_dp_f
#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[3005][3005];
string ans;

void solve(int i, int j, int l) {
    if(l >= max(a.size(), b.size())) return;
    if(i > a.size() || j > b.size()) return;
    if(a[i] == b[j]) {
        ans[l] = a[i];
        solve(i - 1, j - 1, l + 1);
    }
    else {
        if(dp[i][j] == dp[i - 1][j]) solve(i - 1, j, l);
        else solve(i, j - 1, l);
    }
}

int main() {
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    a = " " + a;
    b = " " + b;
    for(int i = 0; i <= n; i ++) dp[i][0] = dp[0][i] = 0;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    ans.resize(dp[n][m]);
    
    solve(n, m, 0);
    for(int i = ans.size() - 1; i >= 0; i --) cout << ans[i];
    // cout << dp[n][m];
}