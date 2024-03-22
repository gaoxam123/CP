#include<bits/stdc++.h>
using namespace std;
int t, k, a[500000], n;
int main(){
	cin>>t;
	while(t--){
		cin>>k>>n;
		for(int i=1;i<=n;i++){
			int tmp;
			cin>>tmp;
			a[i] = k - tmp;
		}
		sort(a+1, a+n+1);
		int sum[500000];
		for(int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
		int l = 0, r = n;
		while(l<r){
			int mid = (l+r)/2;
			if(sum[mid]<k) l = mid + 1;
			else r = mid;
		}
		cout<<l-1<<endl;
	}
}
