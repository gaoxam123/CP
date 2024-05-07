// https://leetcode.com/problems/super-egg-drop/description/
#include <bits/stdc++.h>
using namespace std;

int n, m, t, dp[1005][1005];

int Log(int x) {
	int cnt = 0;
	while(x > 0) {
		cnt ++;
		x /= 2;
	}
	return cnt;
}

int main() {
    for(int i = 1; i <= 1002; i ++) {
        dp[1][i] = i;
    }
    for(int j = 1; j <= 1002; j ++) {
        for(int i = 2; i <= 1002; i ++) {
            dp[i][j] = 1e9;
            if(i > Log(j)) dp[i][j] = dp[i - 1][j];
            else {
                int l = 1, r = j;
                while(l <= r) {
                    int mid = (l + r) / 2;
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][mid - 1], dp[i][j - mid]) + 1);
                    if(dp[i - 1][mid - 1] <= dp[i][j - mid]) {
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
            }
        }
    }
    cin >> t;
    while(t --) {
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
}