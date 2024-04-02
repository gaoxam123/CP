#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, dp[1000005], MOD = 1e9+7, sum[1000005], gg;
signed main() {
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		sum[i] = sum[i-1] + x;
		sum[i] %= MOD;
	}
	if (sum[n] == 0) {
		
	}
	gg = sum[n] / k;
	for (int i = 1; i <= n; i ++) {
		if (sum[i] % gg == 0) {
			dp[sum[i] / gg] += dp[sum[i] / gg - 1] % MOD;
			dp[sum[i] / gg] %= MOD;
			//cout << sum[i] / gg << " " << dp[sum[i] / gg] << endl;
		}
	}
	cout << dp[k - 1] % MOD;
}
