#include<bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m, tong;
vector< pair< pair<int,int>,int > > gg, cc;
bool cmp(pair< pair<int,int>,int > &x, pair< pair<int,int>,int > &y){
    return x.first.second<y.first.second;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        gg.clear(); cc.clear();
        for(int i=1;i<=m;i++){
            int tmp1, tmp2;
            cin>>tmp1>>tmp2;
            gg.push_back(make_pair(make_pair(tmp1, tmp2), i));
        }
        sort(gg.begin(), gg.end(), cmp);
        for(int i=1;i<=2*n;i++) cc.push_back(gg[i-1]);
        sort(cc.begin(), cc.end());
        tong = 0;
        for(int i=0;i<2*n;i++) tong+=cc[i].first.second;
        cout<<tong<<endl;
        for(int i=0;i<n;i++) cout<<cc[i].second<<" "<<cc[2*n-1-i].second<<endl;
    }
}
