#include<bits/stdc++.h>
using namespace std;
int n, l, w;
pair <double, double> a[10005];
bool cmp(pair <double, double> x, pair <double, double> y){
	return x.second > y.second;
}
int main(){
	while(cin>>n>>l>>w){
		int cnt = 0;
		for(int i=0;i<n;i++){
			double pos, rad;
			cin>>pos>>rad;
			if(rad*2 < w){
				continue;
			}
			double tmp;
			tmp = sqrt((double)(4*rad*rad) - w*w)/2;
			a[cnt].first = (double)pos - tmp;
			a[cnt].second = (double)pos + tmp;
			cnt++;
		}
		sort(a, a+cnt, cmp);
		int ans = 0;
		double left = 0.0, right = (double)l;
		while(left < right){
			int tmp = 0;
			for(tmp=0;tmp<cnt;tmp++){
				if(a[tmp].first<=left&&a[tmp].second>left){
					ans++;
					left = a[tmp].second;
					break;
				}
			}
			if(tmp==cnt) break;
		}
		if(left<right) cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
}
