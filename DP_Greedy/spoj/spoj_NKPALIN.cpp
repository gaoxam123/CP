// https://oj.vnoi.info/problem/nkpalin
#include <bits/stdc++.h>
using namespace std;

int n, dp[2005][2005];
string s, ans;

void solve(int i, int j, int l, int r) {
    if(l > r) return;
    if(i == j) ans[l] = s[i];
    else {
        if(s[i] == s[j]) {
            ans[l] = ans[r] = s[i];
            solve(i + 1, j - 1, l + 1, r - 1);
        }
        else {
            if(dp[i][j] == dp[i + 1][j]) solve(i + 1, j, l, r);
            else if(dp[i][j] == dp[i][j - 1]) solve(i, j - 1, l, r);
        }
    }
}

int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i ++) {
        dp[i][i] = 1;
    }
    for(int i = s.size() - 2; i >= 0; i --) {
        for(int j = i + 1; j < s.size(); j ++) {
            if(s[i] == s[j]) {
                if(i == j - 1) dp[i][j] = 2;
                else dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    ans.resize(dp[0][s.size() - 1]);
	solve(0, s.size() - 1, 0, dp[0][s.size() - 1] - 1);
	cout << ans;
}