// https://www.hackerrank.com/challenges/equal/problem?isFullScreen=true
#include <bits/stdc++.h>
using namespace std;

int t, n, a[10009], dp[10009];

int main() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    dp[5] = 1;
    for(int i = 6; i <= 10006; i ++) {
        dp[i] = min(dp[i - 1], dp[i - 2]);
        dp[i] = min(dp[i], dp[i - 5]);
        dp[i] ++;
    }
    cin >> t;
    while(t --) {
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int ans = 1e9;
        for(int j = -5; j <= a[1]; j ++) {
            int sum = 0;
            for(int i = 1; i <= n; i ++) {
                sum += dp[a[i] - j];
            }
            ans = min(sum, ans);
        }
        cout << ans << endl;
    }
}