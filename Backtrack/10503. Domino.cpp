#include<bits/stdc++.h>
using namespace std;
int n, m, dem, gg;
pair <int, int> a[20];
pair <int, int> b[20];
bool check[20];
void backtrack(int pos){
	if(pos==n+1){
		if(a[n].second==a[n+1].first&&gg==0) {
			gg=1;
			dem++;
			return;
		}
		return;
	}
	for(int i=1;i<=m;i++){
		if(b[i].first==a[pos-1].second&&check[i]==0){
			a[pos].first=b[i].first;
			a[pos].second=b[i].second;
			check[i]=1;
			backtrack(pos+1);
			check[i]=0;
		}
		if(b[i].second==a[pos-1].second&&check[i]==0){
			a[pos].first=b[i].second;
			a[pos].second=b[i].first;
			check[i]=1;
			backtrack(pos+1);
			check[i]=0;
		}
	}
}
int main(){
	while(cin>>n){
		if(n==0) return 0;
		gg=0;
		dem=0;
		cin>>m;
		cin>>a[0].first>>a[0].second>>a[n+1].first>>a[n+1].second;
		for(int i=1;i<=m;i++) cin>>b[i].first>>b[i].second;
		backtrack(1);
		if(dem==0) cout<<"NO"<<endl;
		if(gg==1) cout<<"YES"<<endl;
	}
}
