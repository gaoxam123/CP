#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k, a[100005], dp[100005], check;
signed main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		int tmp;
		cin>>tmp;
		a[tmp]++;
	}
	dp[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]==0) {
			dp[i] = (dp[i-1] + dp[i-2])%14062008;
		}
	}
	cout<<dp[n];
}
