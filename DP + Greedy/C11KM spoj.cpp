#include<bits/stdc++.h>
using namespace std;
int n, a[1005], dp[1005][1005], tmp=INT_MAX;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			dp[i][j] = INT_MAX;
		}
	}
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(a[i]>100&&j>0){
				dp[i][j] = min(dp[i-1][j+1], dp[i-1][j-1] + a[i]);
			}
			else dp[i][j] = min(dp[i-1][j+1], dp[i-1][j] + a[i]);
		}
	}
	for(int i=0;i<=n;i++) tmp = min(tmp, dp[n][i]);
	cout<<tmp;
}
