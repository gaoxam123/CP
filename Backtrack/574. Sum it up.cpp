#include<bits/stdc++.h>
using namespace std;
int w, n, a[20], dem;
vector <int> ans;
map< vector <int>, bool> check;
void backtrack(int pos, int sum){
	if(pos==n){
		if(sum==w&&check[ans]==0){
			dem++;
			for(int i=0;i<ans.size();i++){
				cout<<ans[i];
				if(i<ans.size()-1) cout<<"+";
			}
			cout<<endl;
			check[ans] = 1;
		}
		return;
	}
	ans.push_back(a[pos]);
	backtrack(pos+1, sum+a[pos]);
	ans.pop_back();
	backtrack(pos+1, sum);
}
int main(){
	while(cin>> w){
		if(w==0) return 0;
		dem = 0;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<"Sums of "<<w<<":"<<endl;
		backtrack(0, 0);
		if(dem==0) cout<<"NONE"<<endl;
	}
}
