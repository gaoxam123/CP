#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,sum[N],m,a[N],b[N],d[N],dp[N],f[N];
bool cmp(int x,int y){
    return b[x]<b[y];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum[i]=sum[i-1]+x;	
	}
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i]>>d[i];
	b[m+1]=n+1;
	for(int i=1;i<=m;i++){
		for(int j=b[i];j<=min(b[i+1]-1,b[i]+d[i]-1);j++){
			if(j-d[i]+1>b[i-1]) a[j]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0) dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[i-d[a[i]]]+sum[i]-sum[i-d[a[i]]]);
	}
	cout<<dp[n];
}
