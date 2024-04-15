// https://oj.vnoi.info/problem/atcoder_dp_b
#include <bits/stdc++.h>
using namespace std;

int n, k, dp[100005], a[100005];

int main() {
	cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 2; i <= n; i ++) {
        dp[i] = 1e9;
        for(int j = i - 1; j >= max(1, j - k); j --) {
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }
    cout << dp[n];
}