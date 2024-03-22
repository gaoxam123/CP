#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
signed main(){
	cin>>n>>m>>k;
	int l = 1, r = n*m;
	while(l<r){
		int mid = (l+r)/2;
		int dem = 0;
		for(int i=1;i<=n;i++){
			int cccc = mid/i;
			dem += min(cccc, m);
		}
		if(dem>=k) r = mid;
		else l = mid + 1;
	}
	cout<<l;
}
