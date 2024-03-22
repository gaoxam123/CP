#include<bits/stdc++.h>
using namespace std;
int n, m, dp[1505][1505], cola[1505][1505], colb[1505][1505], a[1505][1505][2];
char c;
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> c;
			int x;
			cin >> x;
			if(c == 'A') a[i][j][0] = x;
			else a[i][j][1] = x;
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cola[i][j] = cola[i][j - 1] + a[i][j][0];
			colb[i][j] = colb[i - 1][j] + a[i][j][1];
		}
	}
	for(int i = 2; i <= n; i ++) {
		for(int j = 2; j <= m; j ++) {
			dp[i][j] = dp[i - 1][j - 1] + colb[i - 1][j] + cola[i][j - 1];
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + cola[i][j - 1]);
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + colb[i - 1][j]);
		}
	}
	cout << dp[n][m];
}
