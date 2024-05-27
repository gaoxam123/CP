// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/
#include <bits/stdc++.h>
using namespace std;

int n, a[305], dp[15][305], d, f[305][305];

int main() {
    cin >> n >> d;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        f[i][i] = a[i];
    }
    for(int i = n - 1; i >= 1; i --) {
        for(int j = i + 1; j <= n; j ++) {
            f[i][j] = max(f[i + 1][j], f[i][j - 1]);
        }
    }
    for(int i = 1; i <= n; i ++) {
    	for(int j = 1; j <= d; j ++) {
    		dp[j][i] = 1e9;
    	}
    }
    for(int i = 1; i <= n; i ++) {
        dp[1][i] = f[1][i];
    }
    for(int i = 2; i <= d; i ++) {
        for(int j = i; j <= n; j ++) {
            for(int k = j; k >= i; k --) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + f[k][j]);
            }
        }
    }
    if(dp[d][n] < 1e9) cout << dp[d][n];
    else cout << "-1";
    //cout << dp[6][8];
}