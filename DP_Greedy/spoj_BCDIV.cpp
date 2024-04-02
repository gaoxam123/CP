// https://vn.spoj.com/problems/BCDIV/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, k;
int dp[30][30];

signed main() {
    dp[0][0] = 1;
    for(int j = 1; j <= 25; j ++) {
        for(int i = j; i <= 25; i ++) {
            if(j == 1) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1];
            }
        }
    }
    cin >> t;
    while(t --) {
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
}