// https://codeforces.com/problemset/problem/474/D
#include <bits/stdc++.h>
using namespace std;

int t, k;
long long dp[100005], sum[100005];
int mod = 1e9 + 7;

int main() {
    cin >> t >> k;
    for(int i = 1; i <= 100003; i ++) {
        if(i < k) dp[i] = 1;
        else if(i == k) dp[i] = 2;
        else {
            dp[i] = dp[i - k] % mod + dp[i - 1] % mod;
            dp[i] %= mod;
        }
        sum[i] = sum[i - 1] + dp[i];
        sum[i] %= mod;
    }
    while(t --) {
        int a, b;
        cin >> a >> b;
        cout << (sum[b] + mod - sum[a - 1]) % mod << endl;
    }
}