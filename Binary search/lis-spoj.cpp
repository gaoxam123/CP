#include<bits/stdc++.h>
using namespace std;
int n, a[30005], f[30005], ans;
int binari(int l, int r, int val){
	while(l<r){
		int mid = (l+r+1)/2;
		if(f[mid]<val) l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	f[0] = -1e9;
	for(int i=1;i<=n;i++) f[i]=1e9;
	for(int i=1;i<=n;i++){
		int pos = binari(0, n, a[i]);
		f[pos+1] = a[i];
		if(ans == pos) ans++;
	}
	cout<<ans;
}
