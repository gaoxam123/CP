#include<bits/stdc++.h>
using namespace std;
int n, k, a[1005][1005], sum[1005][1005], ans;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
 		}
	}
	sum[1][1] = a[1][1];
	sum[1][2] = a[1][1] + a[1][2];
	sum[2][1] = a[1][1] + a[2][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
		}
	}
	for(int i=k;i<=n;i++){
		for(int j=k;j<=n;j++){
			ans = max(ans, sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k]);
		}
	}
	cout<<ans;
}
