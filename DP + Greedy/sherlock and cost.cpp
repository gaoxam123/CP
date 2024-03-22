#include<bits/stdc++.h>
using namespace std;
int t, n, a[100005], dp[100005][2];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i][0] = 0;
			dp[i][1] = 0;
		}
		for(int i=2;i<=n;i++){
			dp[i][0] = max(dp[i-1][1] + a[i-1] - 1, dp[i-1][0]);
			dp[i][1] = max(dp[i-1][1] + abs(a[i-1] - a[i]), dp[i-1][0] + a[i] - 1);
		}
		cout<<max(dp[n][1], dp[n][0])<<endl;
	}
}
