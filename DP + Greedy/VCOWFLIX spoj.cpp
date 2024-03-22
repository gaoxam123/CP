#include<bits/stdc++.h>
using namespace std;
int w, n, a[20], dp[20][5005];
int main(){
	cin>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			if(a[i]>j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + a[i]);
		}
	}
	cout<<dp[n][w];
}
