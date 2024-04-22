// https://oj.vnoi.info/problem/thseq
#include <bits/stdc++.h>
using namespace std;
int a[2505], dp[2505][2505], _id[1000005 * 2], *id = _id + 1000005, t, n, ans;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j < i; j ++) {
                int val = a[i] - a[j];
                dp[i][j] = 2;
                if (abs(val) <= 1e6 && id[val] > 0) dp[i][j] = dp[j][id[val]] + 1;
                ans = max(ans, dp[i][j]);
                id[a[j]] = j;
            }
            for (int j = 1; j < i; j ++) id[a[j]] = 0;
        }
        cout << ans << endl;
    }
}