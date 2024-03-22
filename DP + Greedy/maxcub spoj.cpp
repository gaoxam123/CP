#include<bits/stdc++.h>
using namespace std;
int t, n, a[31][31][31], sum[31][31][31], ans = INT_MIN;
int main(){
	cin>>t;
	while(t--){
		ans = INT_MIN;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					cin>>a[i][j][k];
					sum[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					sum[i][j][k] = sum[i-1][j][k] + sum[i][j-1][k] + sum[i][j][k-1] - sum[i-1][j-1][k] - sum[i-1][j][k-1] - sum[i][j-1][k-1] + sum[i-1][j-1][k-1] + a[i][j][k];
				}
			}
		}
		for(int l=1;l<=n;l++){
			for(int i=l;i<=n;i++){
				for(int j=l;j<=n;j++){
					for(int k=l;k<=n;k++){
						ans = max(ans, sum[i][j][k] - sum[i-l][j][k] - sum[i][j-l][k] - sum[i][j][k-l] + sum[i-l][j-l][k] + sum[i-l][j][k-l] + sum[i][j-l][k-l] - sum[i-l][j-l][k-l]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
