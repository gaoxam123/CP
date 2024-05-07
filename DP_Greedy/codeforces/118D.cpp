// https://codeforces.com/problemset/problem/118/D
#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n, m, k1, k2, t = 1e8;
	long long a[2][120][120] = {0};
	cin >> n >> m >> k1 >> k2;
	a[0][0][0] = a[1][0][0] = 1;
	for (long i = 0; i <= n; i ++)
		for (long j = 0; j <= m; j ++) {
			for (long k = 1; k <= k1; k ++)
				a[0][i + k][j]=(a[0][i + k][j] + a[1][i][j]) % t;
			for (long k = 1; k <= k2; k ++)
				a[1][i][j + k]=(a[1][i][j + k] + a[0][i][j]) % t;
		}
	cout << (a[0][n][m] + a[1][n][m]) % t;
}