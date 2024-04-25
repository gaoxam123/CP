// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, dp[505], f[505], mod = 1e9 + 7;

signed main() {
    cin >> n;
    dp[1] = 1;
    f[1] = 1, f[2] = 3;
    for(int i = 3; i <= 3 * n; i ++) {
        f[i] = f[i - 1] + i;
    }
    for(int i = 2; i <= n; i ++) {
        dp[i] = dp[i - 1] * f[2 * (i - 1) + 1];
        dp[i] %= mod; // * number of possibles pos to place the next delivery
    }
    cout << dp[n];
}

// a a a a : 1 -> 1, 2 -> 2, 3 -> 