#include<bits/stdc++.h>
using namespace std;
int t, n, a[100005], dp[100005], ans = INT_MIN, sum, ans2, check, mm;
int main(){
	cin>>t;
	while(t--){
		ans2 = 0;
		sum = 0;
		check = 0;
		mm = INT_MIN;
		ans = INT_MIN;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mm = max(mm, a[i]);
			if(a[i]>=0){
				check = 1;
				ans2+=a[i];
			}
			dp[i]=INT_MIN;
		}
		for(int i=1;i<=n;i++){
			sum = max(a[i], sum + a[i]);
			ans = max(ans, sum);
		}
		cout<<ans<<" ";
		if(check == 0) cout<<mm<<endl;
		else cout<<ans2<<endl;
	}
}
