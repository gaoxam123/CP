#include<bits/stdc++.h>
using namespace std;
int n, a[25005], dp[25005][2];
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	dp[1][1] = a[1];
	dp[1][0] = a[1];
	for(int i=2;i<n;i++) {
		dp[i][0] = dp[i-1][1];
		dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + a[i];
	}
	cout<<dp[n-1][1];
}
