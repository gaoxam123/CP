#include<bits/stdc++.h>
using namespace std;
int t, n, a[10005], ans, Min = 1e9, dp[10005];
int main(){
	cin>>t;
	while(t--){
		Min = 1e9;
		ans = 1e9;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			Min = min(Min, a[i]);
		}
		dp[0] = 0;
		for(int i=1;i<=1000;i++) dp[i] = 1e9;
		for(int i=1;i<=1000;i++) {
			if(i>=1) dp[i] = min(dp[i], dp[i-1] + 1);
			if(i>=2) dp[i] = min(dp[i], dp[i-2] + 1);
			if(i>=5) dp[i] = min(dp[i], dp[i-5] + 1);
		} 
		for(int j=0;j<=Min;j++){
			int sum = 0;
			for(int i=1;i<=n;i++){
				sum+=dp[a[i]-j];
			}
			ans = min(ans, sum);
		}
		cout<<ans<<endl;
	}
}
