// https://oj.vnoi.info/problem/chntower
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, dp[100][100];

signed main() {
    for(int i = 1; i <= 64; i ++) {
        for(int j = 3; j <= 64; j ++) {
            if(j == 3) dp[i][j] = pow(2, i) - 1;
            else if(i < j) {
                dp[i][j] = 2 * i - 1;
            }
            else if(i == j) {
                dp[i][j] = 2 * i + 1;
            }
            else {
                dp[i][j] = 1e18;
                for(int k = 1; k < i; k ++) {
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + 2 * dp[k][j]);
                }
            }
        }
    }
    while(cin >> n) {
        cin >> m;
        cout << dp[n][m] << endl;
    }
}