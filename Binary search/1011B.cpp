#include<bits/stdc++.h>
using namespace std;
int n, m, k;
vector <int> a;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int tmp;
		cin>>tmp;
		a[tmp]++;
	}
	int l = 1, r = n;
	while(l<r){
		k = 0;
		int mid = (l+r)/2;
		vector <int> b(a);
		for(int i=1;i<=n;i++){
			while(b[i]>=mid){
				k++;
				b[i]-=mid;
			}
		}
		if(k>=n) l = mid + 1;
		else r = mid;
	}
	cout<<l;
}
