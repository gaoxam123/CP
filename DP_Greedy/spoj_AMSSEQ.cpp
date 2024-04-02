// https://oj.vnoi.info/problem/amsseq
#include <bits/stdc++.h>
using namespace std;

int n, k, a[10005], dp[10005], ans;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    ans = -1e9 - 1;
    memset(dp, -1000000, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i ++) {
        if(i == 1) {
            dp[i] = a[i];
            ans = max(ans, dp[i]);
        }
        else {
            int start = max(0, i - k);
            for(int j = start; j < i; j ++) {
                dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += a[i];
            ans = max(ans, dp[i]);
        }
    }
    cout << ans;
}