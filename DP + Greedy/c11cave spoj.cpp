#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, h, dp[500005], cnt, ans = 1e9;
signed main() {
	cin>>n>>h;
	for(int i=1;i<=n;i++) {
		int a;
		cin>>a;
		if(i%2 == 0) {
			dp[1] ++;
			dp[a + 1] --;
		}
		else {
			dp[h - a + 1] ++;
			dp[h + 1] --;
		}
	}
	for(int i=1;i<=h;i++) dp[i] += dp[i-1];
	for(int i=1;i<=h;i++) ans = min(ans, dp[i]);
	for(int i=1;i<=h;i++) if(dp[i] == ans) cnt++;
	cout<<ans<<" "<<cnt;
}
