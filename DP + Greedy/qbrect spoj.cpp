#include<bits/stdc++.h>
using namespace std;
int cnt, n, m, a[1005][1005], ans, col[1005][1005];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m;j ++) {
			col[i][j] = col[i - 1][j] + a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i ; j <= n; j ++) {
			cnt = 0;
			for(int k = 1; k <= m; k ++) {
				if(col[j][k] - col[i - 1][k] == j - i + 1) {
					cnt ++;
					ans = max(ans, cnt * (j - i + 1));
				}
				else cnt = 0;
			}
		}
	}
	cout << ans;
}
//KAGAIN
