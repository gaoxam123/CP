#include<bits/stdc++.h>
using namespace std;
string a, b;
int dp[1005][1005];
int main(){
	cin>>a>>b;
	int n = a.size();
	int m = b.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout<<dp[n-1][m-1];
}
