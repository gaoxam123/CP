// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
#include <bits/stdc++.h>
using namespace std;

int n, m, arr[105], a[105], f[105][105], dp[105][105], sum[105];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + m + 1);
    arr[m + 1] = n;
    m ++;
    for(int i = 1; i <= m; i ++) {
        a[i] = arr[i] - arr[i - 1];
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = i;
    }
    for(int j = 2; j <= m; j ++) {
        for(int i = j - 1; i >= 1; i --) {
            dp[i][j] = 1e9;
            for(int k = f[i][j - 1]; k <= f[i + 1][j]; k ++) {
                if(dp[i][j] > dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
                    f[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][m];
}