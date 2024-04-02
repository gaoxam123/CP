#include<bits/stdc++.h>
using namespace std;
string s;
int a[305], n, k, gg[305][305][305];
int dp (int i, int j, int k1) {
	if (i > j) return 1;
	if (gg[i][j][k1] >= 0) return gg[i][j][k1];
	int k2 = a[n] - (a[j] - a[i - 1]) - k1;
	if (s[i] == 'W' || (s[i] == 'B' && k1 < k)) {
		if (dp(i + 1, j, k2) == 0) 
			return gg[i][j][k1] = 1;
	}
	if (s[j] == 'W' || (s[j] == 'B' && k1 < k)) {
		if (dp(i, j - 1, k2) == 0) 
			return gg[i][j][k1] = 1;
	}
	return gg[i][j][k1] = 0;
}
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	cin >> s;
	s = ' ' + s;
	memset(gg, -1, sizeof(gg));
	for (int i = 1; i <= n; i ++) {
		if (s[i] == 'B') {
			a[i] ++;
			a[i] += a[i-1];
		}
	}
	if (dp(1, n, 0) == 1) cout << "YES";
	else cout << "NO";
}
