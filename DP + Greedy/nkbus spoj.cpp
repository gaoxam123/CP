#include<bits/stdc++.h>
using namespace std;
int n, m, dp[200005], ans, cnt, arr[200005], p;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		int a, b;
		cin>>a>>b;
		dp[i+1] = dp[i] + a;
		for(int j=cnt+1;j<=cnt+b;j++){
			int t;
			cin>>t;
			arr[j] = max(p, t - dp[i]);
		}
		cnt+=b;
	}
	sort(arr+1, arr+cnt+1);
	cout<<dp[n+1]+arr[m];
}
