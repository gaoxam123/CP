#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, L[4], C[4], p[4], s, t;
int a[100005], dp[100005];

signed main() {
	for(int i = 1; i <= 3; i ++) cin >> L[i];
	for(int i = 1; i <= 3; i ++) cin >> C[i];
	cin >> n >> s >> t;
	for(int i = 2; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= 3; i ++) p[i] = s;
	for(int i = s + 1; i <= t; i ++) {
		dp[i] = 1e18;
		for(int j = 3; j >= 1; j --) {
			while(a[i] - a[p[j]] > L[j]) p[j] ++;
			dp[i] = min(dp[i], dp[p[j]] + C[j]);
			p[j - 1] = p[j];
		}
	}
	cout << dp[t];
}