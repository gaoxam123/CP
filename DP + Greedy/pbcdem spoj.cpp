#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n, dp[4005][4005], ans;
signed main() {
	cin>>n;
	dp[0][0] = 1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			dp[i][j] = dp[i-j][j] + dp[i-j][j-1];
		}
	}
	for(int i=2;i<=n;i++) ans+=dp[n][i];
	cout<<ans;
}
