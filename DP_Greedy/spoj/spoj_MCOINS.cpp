// https://oj.vnoi.info/problem/mcoins
#include <bits/stdc++.h>
using namespace std;

int k, l, m, n, dp[1000005];

int main() {
    cin >> k >> l >> m;
    dp[k] = 1, dp[l] = 1, dp[1] = 1;
    for(int i = 2; i < min(k, l); i ++) dp[i] = 1 - dp[i - 1];
    if(k > l) swap(k, l);
    for(int i = k + 1; i < l; i ++) {
    	if(!dp[i - 1] || !dp[i - k]) dp[i] = 1;
    }
    for(int i = l + 1; i <= 1000000; i ++) {
    	if(!dp[i - 1] || !dp[i - k] || !dp[i - l]) dp[i] = 1;
    }
    while(m --) {
        cin >> n;
        if(dp[n]) cout << "A";
        else cout << "B";
    }
    // cout << dp[8];
}
