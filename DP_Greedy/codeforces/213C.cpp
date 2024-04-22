// https://codeforces.com/contest/213/problem/C
#include<bits/stdc++.h>
#define int long long
using namespace std;

int const N = 666;
int n, a[N][N], f[N][N];

signed main(){
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> a[i][j];
	memset(f, 0xaa, sizeof(f));
	f[1][1] = a[1][1];
	for(int k = 2; k <= 2 * n; k ++)
		for(int i = k - 1; i > 0; i --)
			for(int j = k - 1; j > 0; j --)
                f[i][j] = max(max(f[i][j], f[i - 1][j - 1]), max(f[i - 1][j], f[i][j - 1])) + a[i][k - i] + a[j][k - j] * (i != j);
    cout << f[n][n] - a[1][1];
}