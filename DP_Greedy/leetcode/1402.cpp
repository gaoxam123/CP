// https://leetcode.com/problems/reducing-dishes/description/
#include <bits/stdc++.h>
using namespace std;

int n, a[505], dp[505][505], ans = -1e9;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 0; i <= n; i ++) {
    	for(int j = 1; j <= n; j ++) {
    		dp[i][j] = -1e9;
    	}
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i] * j);
        }
    }
    for(int i = 0; i <= n; i ++) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
}