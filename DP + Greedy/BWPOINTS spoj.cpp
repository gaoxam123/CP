#include<bits/stdc++.h>
using namespace std;
int n, cnt, ans, maulon;
pair <int, int> a[200005];
bool cmp(pair<int, int> gg, pair<int, int> ff){
	return gg.first<ff.first;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[++cnt].first;
		a[i].second = 0;
	}
	for(int i=n+1;i<=2*n;i++){
		cin>>a[++cnt].first;
		a[i].second = 1;
	}
	sort(a+1, a+cnt+1, cmp);
	maulon = a[1].second;
	for(int i=2;i<=cnt;i++){
		if(a[i].second + maulon==1) {
			ans++;
			maulon = -1;
		}
		else maulon = a[i].second;
	}
	cout<<ans;
}
