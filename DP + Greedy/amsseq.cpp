#include<bits/stdc++.h>
using namespace std;
int n, k, a[10005], dp[10005], ans;
int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		dp[i] = -1e9;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=min(i, k);j++) {
			if(i>=j) dp[i] = max(dp[i], dp[i-j] + a[i]);
		}
	}
	for(int i=0;i<=n;i++) {
		if(dp[i] > 0) ans = max(ans, dp[i]);
	}
	cout<<ans;
}
