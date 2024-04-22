// https://www.hackerrank.com/challenges/angry-children-2/problem?isFullScreen=true
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, a[100005], ans, sum[100005], dp;

signed main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 2; i <= k; i ++) {
        dp += (i - 1) * (a[i] - a[i - 1]);
        ans += dp;
    }
    int curr = ans;
    for(int i = k + 1; i <= n; i ++) {
        curr = curr + (k - 1) * a[i] - 2 * (sum[i - 1] - sum[i - k]) + (k - 1) * a[i - k];
        ans = min(curr, ans);
    }
    cout << ans;
}