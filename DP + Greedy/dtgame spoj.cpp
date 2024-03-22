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
			for(int k=s[i][j-1];k<=s[i+1][j];k++) {
				int ans = min(dp[i][k] + a[k] - a[i-1], dp[k+1][j] + a[j] - a[k]);
				if(dp[i][j] < ans) {
					dp[i][j] = ans;
					s[i][j] = k;
				}
			}
		}
	}
	cout<<dp[1][n];
}
