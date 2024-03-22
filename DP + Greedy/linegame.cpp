#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, ans, a, b, c;
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		c = a;
		if (a < b + x) a = b + x;
		if (b < c - x) b = c - x;
		ans = max(ans, max(a, b));
	}
	cout << ans;
}	
