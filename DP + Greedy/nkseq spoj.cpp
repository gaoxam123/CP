#include<bits/stdc++.h>
using namespace std;
int n, a[100005], dp[100005];
int main(){
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<=0) cout<<"0";
	else{
		int tmp=0;
		dp[n+1]=INT_MAX;
		int ans=0;
		for(int i=1;i<=n;i++){
			tmp+=a[i];
			dp[n+1]=min(dp[n+1],tmp);
		}
		if(dp[n+1]>0) ans++;
		for(int i=n;i>=2;i--){
			dp[i]=min(dp[i+1]+a[i],a[i]);
			if(dp[i]>0) ans++;
		}
		cout<<ans;
	}
}
