// https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
#include <bits/stdc++.h>
using namespace std;

int n, a[205][205], dp[205][205], ans;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i ++) {
        dp[1][i] = a[1][i];
    }
    for(int i = 2; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            dp[i][j] = 1e9;
            for(int k = 1; k <= n; k ++) {
                if(k != j) dp[i][j] = min(dp[i][j], dp[i - 1][k] + a[i][j]);
            }
            if(i == n) ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}