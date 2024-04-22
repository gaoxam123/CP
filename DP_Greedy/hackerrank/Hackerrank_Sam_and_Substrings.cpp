// https://www.hackerrank.com/challenges/sam-and-substrings/problem
#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
int dp[200005], a[200005], sum[200005], mod = 1e9 + 7;

signed main() {
    cin >> s;
    for(int i = 1; i <= s.size(); i ++) {
        a[i] = s[i - 1] - '0';
    }
    dp[1] = a[1];
    int n = s.size();
    for(int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + a[i] * i;
        sum[i] %= mod;
    }
    for(int i = 2; i <= n; i ++) {
        dp[i] = dp[i - 1] * 10 + sum[i];
        dp[i] %= mod;
    }
    cout << dp[n];
}