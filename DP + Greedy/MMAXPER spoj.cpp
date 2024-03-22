#include<bits/stdc++.h>
using namespace std;
int n, a[1000], b[1000], dp[1000][2];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	dp[1][0] = a[1];
	dp[1][1] = b[1];
	for(int i=2;i<=n;i++){
		dp[i][0] = max(dp[i-1][0] + abs(b[i] - b[i-1]), dp[i-1][1] + abs(b[i] - a[i-1])) + a[i];
		dp[i][1] = max(dp[i-1][0] + abs(a[i] - b[i-1]), dp[i-1][1] + abs(a[i] - a[i-1])) + b[i];
	}
	cout<<max(dp[n][0], dp[n][1]);
}
