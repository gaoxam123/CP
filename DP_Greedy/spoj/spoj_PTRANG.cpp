// https://oj.vnoi.info/problem/ptrang
#include <bits/stdc++.h>
using namespace std;

int n, a[6005], L, dp[6005];

int main() {
    cin >> n >> L;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        dp[i] = 1e9;
        int S = L;
        int j = i;
        while(j > 0 && S - a[j] >= 0) {
            dp[i] = min(dp[i], max(dp[j - 1], S - a[j]));
            S -= a[j];
            j --;
        }
    }
    cout << dp[n];
}