#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[100005], L[100005], R[100005], sum;
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) L[i] = max(L[i-1], a[i-1]);
	for(int i=n;i>=1;i--) R[i] = max(R[i+1], a[i+1]);
	for(int i=1;i<=n;i++) sum += max((long long) 0, min(L[i], R[i]) - a[i]);
	cout<<sum;
}
