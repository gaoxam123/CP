#include<bits/stdc++.h>
using namespace std;
int n, l, a[6005], dp[6005];
int main(){
	cin>>n>>l;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		dp[i] = l + 1;
		int j = i, S = a[i];
		while(j>0 && S <= l) {
			dp[i] = min(dp[i], max(dp[j-1], l - S));
			S += a[--j];
		}
	}
	cout<<dp[n];
}
