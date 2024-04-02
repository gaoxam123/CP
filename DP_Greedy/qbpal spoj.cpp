#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n, dp[125][125];
signed main(){
	cin>>s;
	n = s.size();
	for(int i=0;i<n;i++) {
		dp[i][i] = 1;
	}
	for(int k=1;k<n-1;k++) {
		for(int i=0;i<n-k;i++) {
			int j=i+k;
			dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
			if(s[i] == s[j]) dp[i][j] += dp[i+1][j-1] + 1;
		}
	}
	cout<<dp[0][n-1];
}
