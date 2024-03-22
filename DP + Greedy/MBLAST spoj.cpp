#include<bits/stdc++.h>
using namespace std;
string a, b;
int n, m, dp[2005][2005], k;
int main(){
	cin>>a>>b;
	a = '.' + a;
	b = '.' + b;
	cin>>k;
	int n = a.size();
	int m = b.size();
	for(int i=0;i<n;i++) dp[i][0] = i*k;
	for(int j=0;j<m;j++) dp[0][j] = j*k;
	for(int i=1;i<n;i++) {
		for(int j=1;j<m;j++) {
			dp[i][j] = min(dp[i-1][j-1] + abs(a[i] - b[j]), min(dp[i-1][j-1] + 2*k, min(dp[i-1][j] + k, dp[i][j-1] + k)));
		}
	}
	cout<<dp[n-1][m-1];
}
