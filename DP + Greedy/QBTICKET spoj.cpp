#include<bits/stdc++.h>
using namespace std;
int n, a[100005], dp[100005][4], l1, l2, l3, c1, c2, c3, l, r;
int main(){
	cin>>l1>>l2>>l3>>c1>>c2>>c3;
	cin>>n;
	cin>>l>>r;
	for(int i=1;i<n;i++) {
		int tmp;
		cin>>tmp;
		a[i] = tmp - a[i-1];
		dp[i][1] = INT_MAX;
	}
	for(int i=l;i<=r;i++){
		if(a[i]>l2) dp[i][3] = min(dp[i-1][3], min(dp[i-1][2], dp[i-1][1])) + c3;
		else if(a[i]>l1) {
			dp[i][2] = min(dp[i-1][3], min(dp[i-1][2], dp[i-1][1])) + c2;
			dp[i][3] = min(dp[i-1][3], min(dp[i-1][2], dp[i-1][1])) + c3;
		}
		else {
			dp[i][1] = min(dp[i-1][3], min(dp[i-1][2], dp[i-1][1])) + c2;
			dp[i][2] = min(dp[i-1][3], min(dp[i-1][2], dp[i-1][1])) + c2;
			dp[i][3] = min(dp[i-1][3], min(dp[i-1][2], dp[i-1][1])) + c3;
		}
	}
	cout<<min(dp[r][1], min(dp[r][2], dp[r][3]));
}
