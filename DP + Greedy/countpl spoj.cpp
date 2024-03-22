#include<bits/stdc++.h>
using namespace std;
string s;
int n, dp[256];
bool check(int a, int b) {
	for(int i=a;i<=b;i++) {
		if(s[i] != s[a+b-i]) return false;
	}
	return true;
}
int main() {
	cin>>s;
	s = ' ' + s;
	for(int i=1;i<s.size();i++) dp[i] = dp[i-1] + 1;
	for(int i=2;i<s.size();i++) {
		for(int j=i-1;j>=0;j--) {
			if(check(j+1, i)) dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	cout<<dp[s.size()-1];
}
