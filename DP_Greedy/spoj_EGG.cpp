// https://oj.vnoi.info/problem/egg
#include <bits/stdc++.h>
using namespace std;

int t, n, m, dp[1005][1005];

int Log(int x) {
	int cnt = 0;
	while(x > 0) {
		cnt ++;
		x/=2;
	}
	return cnt;
}

int main() {
    for(int j = 1; j <= 1000; j ++) {
        dp[1][j] = j;
    }
    for(int j = 1; j <= 1000; j ++) {
        for(int i = 2; i <= 1000; i ++) {
            dp[i][j] = 1e9;
            if(i > Log(j)) dp[i][j] = dp[i - 1][j];
            else
                for(int k = 1; k <= j; k ++) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
                }
        }
    }
    cin >> t;
    while(t --) {
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
}