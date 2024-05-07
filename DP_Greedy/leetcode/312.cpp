// https://leetcode.com/problems/burst-balloons/description/
#include <bits/stdc++.h>
using namespace std;

int n, a[305], dp[305][305];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    a[0] = 1, a[n + 1] = 1;
    for(int i = n - 1; i >= 0; i --) {
        for(int j = i + 1; j <= n + 1; j ++) {
            for(int k = i + 1; k < j; k ++) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
            }
        }
    }
    cout << dp[0][n + 1];
}