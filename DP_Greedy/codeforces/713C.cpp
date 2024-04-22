// https://codeforces.com/contest/713/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[5005], dp[5005], b[5005];

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] -= i;
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(j == 1) dp[j] += abs(a[i] - b[j]);
            else dp[j] = min(dp[j - 1], dp[j] + abs(a[i] - b[j]));
        }
    }
    cout << dp[n];
}