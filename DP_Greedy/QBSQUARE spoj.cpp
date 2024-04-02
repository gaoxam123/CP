/*#include<bits/stdc++.h>
using namespace std;
int m, n, a[1005][1005], dp[1005][1005], ans;
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int l = 0, r = min(i, j);
			while(l<r) {
				int mid = (l+r)/2;
				int sum = dp[i][j] - dp[i-mid][j] - dp[i][j-mid] + dp[i-mid][j-mid];
				if(sum == mid*mid) l = mid+1;
				else r = mid;
			}
			ans = max(ans, l);
			l = 0, r = min(i, j);
			while(l<r) {
				int mid = (l+r)/2;
				int sum = dp[i][j] - dp[i-mid][j] - dp[i][j-mid] + dp[i-mid][j-mid];
				if(sum == 0) l = mid+1;
				else r = mid;
			}
			ans = max(ans, l);
		}
	}
	cout<<ans - 1;
}*/
#include<bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005], dp[1005][1005], ans = 1;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int j=1;j<=m;j++) dp[1][j]=1;
	for(int i=1;i<=n;i++) dp[i][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1] && a[i][j] == a[i-1][j-1])
				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
			else
				dp[i][j]=1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout<<ans;
}
