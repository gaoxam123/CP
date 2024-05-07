#include <bits/stdc++.h>

using namespace std;

const long long INF64 = 1e18;
int n, k, x;

int main() {
	cin >> n >> k >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, -INF64));
	
	dp[0][x] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < x; ++j) {
			for (int p = 1; p <= k; ++p) {
				if (i - p < 0) break;
				if (dp[i - p][j + 1] == -INF64) {
					continue;
				}
				dp[i][j] = max(dp[i][j], dp[i - p][j + 1] + a[i - 1]);
			}
		}
	}
	
	long long ans = -INF64;
	for (int i = n - k + 1; i <= n; ++i) {
		ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
	}
	if (ans == -INF64) ans = -1;
	cout << ans << endl;
}