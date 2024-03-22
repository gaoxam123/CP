#include<bits/stdc++.h>
using namespace std;
int n, h, t, a[20], check;
void backtrack(int pos){
	if(pos==n){
		check=0;
		for(int i=0;i<n;i++) {
			if(a[i]==1) check++;
		}
		if(check==h) for(int i=0;i<n;i++) cout<<a[i];
		if(check==h) cout<<endl;
		return;
	}
	for(int i=0;i<=1;i++){
		a[pos]=i;
		backtrack(pos+1);
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>h;
		backtrack(0);
		if(t>0) cout<<endl;
	}
}
