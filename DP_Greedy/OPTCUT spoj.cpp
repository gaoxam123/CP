#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[2005], sum, ans, dp[2005][2005], s[2005][2005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i] += a[i-1];
		s[i][i] = i;
	}
	for(int j=2;j<=n;j++) {
		for(int i=j-1;i>=1;i--) {
			dp[i][j] = 1e9;
			for(int k=s[i][j-1];k<=s[i+1][j];k++) {
				if(dp[i][j] > dp[i][k] + dp[k+1][j] + a[j] - a[i-1]) {
					dp[i][j] = dp[i][k] + dp[k+1][j] + a[j] - a[i-1];
					s[i][j] = k;
				}
			}
		}
	}
	cout<<dp[1][n];
}
