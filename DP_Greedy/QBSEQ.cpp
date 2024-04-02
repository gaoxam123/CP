#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1005];
int dp[1005][1005];
int sub(int x,int y){
	int sum=(x-y)%k;
	if(sum<0) sum=sum+k;
	return sum;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//a[i]%=k;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<k;j++){
			dp[i][j]=INT_MIN;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			//chon a[i]
			//khong chon a[i]
			dp[i][j]=max(dp[i-1][j],dp[i-1][sub(j,a[i])]+1);
		}
	}
	cout<<dp[n][0];
}
