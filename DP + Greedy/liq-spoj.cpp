#include<bits/stdc++.h>
using namespace std;
int n, a[1005], dp[1005], ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[j]<a[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout<<ans;
}
