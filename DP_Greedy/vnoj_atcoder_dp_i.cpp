// https://oj.vnoi.info/problem/atcoder_dp_i
#include <bits/stdc++.h>
using namespace std;

int n;
double a[3005], dp[3005][3005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        dp[i][0] = dp[i - 1][0] * (1 - a[i]);
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= i; j ++) {
            if(i == j) dp[i][j] = dp[i - 1][j - 1] * a[i];
            else {
                dp[i][j] = dp[i - 1][j] * (1 - a[i]) + dp[i - 1][j - 1] * a[i];
            }
        }
    }
    double ans = 0;
    for(int i = n / 2 + 1; i <= n; i ++) ans += dp[n][i];
    cout << fixed << setprecision(10) << ans;
}