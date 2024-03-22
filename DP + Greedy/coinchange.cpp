#include<bits/stdc++.h>
using namespace std;
#define int long long
int v, n, a[100], dp[100][300];
signed main(){
	cin>>v>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			if(a[i]>j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] + dp[i][j-a[i]];
		}
	}
	cout<<dp[n][v];
}
