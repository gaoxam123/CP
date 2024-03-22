#include<bits/stdc++.h>
using namespace std;
int n, a[60005], b[60005], dp[60005][3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][0] = INT_MAX;
		dp[i][1] = INT_MAX;
		dp[i][2] = INT_MAX;
	}
	for(int i=1;i<n;i++){
		cin>>b[i];
	}
	dp[1][1] = a[1];
	dp[1][2] = b[2];
	for(int i=1;i<=n;i++){
		if(i>1) dp[i][0] = dp[i-1][2];
		dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + a[i];
		if(i<n) dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b[i];
	}
	cout<<min(dp[n][0], dp[n][1]);
}
