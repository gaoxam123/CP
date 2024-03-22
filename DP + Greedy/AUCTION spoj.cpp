#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[1005], ans = INT_MIN, ind, tmp;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1, a+m+1);
	for(int i=m;i>=m-min(m, n)+1;i--){
		tmp++;
		if(a[i]*tmp>ans) {
			ans = a[i]*tmp;
			ind = a[i];
		}
	}
	cout<<ind<<" "<<ans;
}
