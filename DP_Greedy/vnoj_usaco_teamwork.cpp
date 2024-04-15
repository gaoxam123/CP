// https://oj.vnoi.info/problem/usaco18dg_teamwork
#include <bits/stdc++.h>
using namespace std;

int n, k, a[10005], dp[10005];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dp[0] = 0;
    dp[1] = a[1];
    for(int i = 2; i <= n; i ++) {
        int m = a[i];
        for(int j = i - 1; j >= max(0, i - k); j --) {
            dp[i] = max(dp[i], dp[j] + (i - j) * m);
            m = max(m, a[j]);
        }
    }
    cout << dp[n];
}