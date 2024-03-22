#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[10005], b[10005], dp[10005][10005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	dp[1][1] = b[1];
	for(int i=2;i<=n;i++){
		dp[i][0] = dp[i-1][1] + a[i];
		if(i<=n/2) dp[i][i] = dp[i-1][i-1] + b[i];
		for(int j=1;j<i;j++){
			dp[i][j] = min(dp[i-1][j-1] + b[i], dp[i-1][j+1] + a[i]);
		}
	}
	cout<<dp[n][0];
}
