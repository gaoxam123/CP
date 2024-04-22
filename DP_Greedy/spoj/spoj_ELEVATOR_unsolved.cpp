#include <bits/stdc++.h>
using namespace std;
#define int long long
int k, ans;
struct cc {
	int h;
	int c;
	int a;
} bo[405];
bool cmp (cc &x, cc &y) {
	return x.a < y.a;
}
bool check[40005];
signed main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> k;
	for (int i = 1; i <= k; i ++) {
		cin >> bo[i].h >> bo[i].a >> bo[i].c;
	}
	check[0] = 1;
	sort(bo + 1, bo + k + 1, cmp);
	
	cout << ans;
}
