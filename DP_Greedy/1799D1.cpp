// https://codeforces.com/contest/1799/problem/D1
#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, k, a[5005], cold[5005], hot[5005], dp[5005][5005];

int cost(int i, int j) {
    return a[i] == a[j] ? hot[a[j]] : cold[a[j]]; 
}

signed main() {
    cin >> t;
    while(t --) {
        cin >> n >> k;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        for(int i = 1; i <= k; i ++) {
            cin >> cold[i];
        }
        for(int i = 1; i <= k; i ++) {
            cin >> hot[i];
        }
        for(int i = 0; i <= n; i ++) {
            for(int j = 0; j <= n; j ++) {
                dp[i][j] = 1e18;
            }
        }
        dp[0][0] = 0;
        int ans = 1e18;
        for(int i = 1; i <= n; i ++) {
            for(int j = 0; j < i; j ++) {
                dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + cost(j, i));
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost(i - 1, i));
                if(i == n) ans = min(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
}