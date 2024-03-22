#include<bits/stdc++.h>
using namespace std;
int t, n, dp[1000005], f[1000005], MOD = 10000;
int main() {
	dp[0] = dp[1] = 1;
	for(int i=2;i<=1000000;i++) {
		//dp[i] = (dp[i-1] + dp[i-2] + 2*(f[i-1]))%MOD;
		//f[i] = (dp[i-2] + f[i-1])%MOD; 
		dp[i] = 2*dp[i-1] + dp[i-3];
	}
	cin>>t;
	while(t--) {
		cin>>n;
		cout<<dp[n]<<endl;
	}
}
