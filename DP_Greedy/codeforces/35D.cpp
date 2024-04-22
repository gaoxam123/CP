// https://codeforces.com/problemset/problem/35/D
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x, a[105], dp[105][10005];

signed main() {
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    cin >> n >> x;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] *= (n - i + 1);
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= x; j ++) {
            if(a[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + 1);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][x];
}