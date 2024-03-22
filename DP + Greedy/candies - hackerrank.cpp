#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], ans[100005], sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=1;
    }
    for(int i=2;i<=n;i++){
    	if(a[i]>a[i-1]) ans[i]+=ans[i-1];
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]>a[i+1]&&ans[i]<=ans[i+1]) ans[i] = ans[i+1]+1;
	}
	for(int i=1;i<=n;i++){
		sum+=ans[i];
	}
	cout<<sum;
}
