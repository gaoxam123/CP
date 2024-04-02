#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000];
int dp[100000];
int sum=0;
int s[100000];
int main(){
	s[0]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		s[i]+=sum;
	}
	if(sum<=0) cout<<"0";
	else{
		if(a[1]>0) dp[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]>0&&s[i]+a[i]>0) dp[i]=dp[i-1]+1;
			else dp[i]=dp[i-1];
		}
		cout<<dp[n];
	}
}
