#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k, t, dp[26][26];
signed main() {
	dp[0][0] = 1;
	for(int i=1;i<=25;i++) {
		for(int j=1;j<=i;j++) {
			dp[i][j] += dp[i-1][j-1] + dp[i-1][j] * j;
		}
	}
	cin>>t;
	while(t--) {
		cin>>n>>k;
		cout<<dp[n][k]<<endl;
	}
} 
