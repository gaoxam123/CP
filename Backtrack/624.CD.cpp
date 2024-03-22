#include<bits/stdc++.h>
using namespace std;
int n, a[25], w, check[25], Max = -1e9;
vector <int> ans, test;
void backtrack(int pos, int sum){
	if(pos==n){
		if(sum>Max&&sum<=w){
			Max = sum;
			ans = test;
		}
		return;
	}
	test.push_back(a[pos]);
	backtrack(pos+1, sum+a[pos]);
	test.pop_back();
	backtrack(pos+1, sum);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>w){
		Max = -1e9;
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		backtrack(0, 0);
		int gg=0;
		for(int i=0;i<ans.size();i++){
			gg+=ans[i];
			cout<<ans[i]<<" ";
		}
		cout<<"sum:"<<gg<<endl;
	}
}
