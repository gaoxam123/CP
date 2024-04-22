// https://oj.vnoi.info/problem/ctnbulls
#include <bits/stdc++.h>
using namespace std;
 
long long n, k, dp[100005], mod = 2111992;

int main() {
    cin >> n >> k;
    dp[0] = 1;
    for(int i = 1; i <= n; i ++) {
        if(i <= k) dp[i] = i + 1;
        else {
            dp[i] = dp[i - 1] % mod + dp[i - k - 1] % mod;
            dp[i] %= mod;
        }
    }
    cout << dp[n];
}